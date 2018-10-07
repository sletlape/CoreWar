/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 18:59:14 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/24 14:35:22 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static void		process_instruction(t_champ *champ, t_arena *arena,
		t_func *f)
{
	unsigned char	op;

	if (champ->wait > 1)
	{
		champ->wait--;
		return ;
	}
	op = arena->arena[champ->pc];
	if (op >= 1 && op <= 16)
		f[op - 1](champ->pc, arena, champ);
	else
		champ->pc = (champ->pc >= (MEM_SIZE - 1)) ? 0 : champ->pc + 1;
}

static void		fill_functions(t_func *f)
{
	f[0] = &ft_live;
	f[1] = &ft_ld;
	f[2] = &ft_st;
	f[3] = &ft_add;
	f[4] = &ft_sub;
	f[5] = &ft_and;
	f[6] = &ft_or;
	f[7] = &ft_xor;
	f[8] = &ft_zjmp;
	f[9] = &ft_ldi;
	f[10] = &ft_sti;
	f[11] = &ft_fork;
	f[12] = &ft_lld;
	f[13] = &ft_lldi;
	f[14] = &ft_lfork;
	f[15] = &ft_aff;
}

static int		check_alive(t_arena *arena)
{
	int		max_lives;

	max_lives = check_player(arena);
	if (max_lives == 0)
		return (FALSE);
	if (max_lives >= NBR_LIVE)
		arena->cycles_to_die -= CYCLE_DELTA;
	else
		arena->checks++;
	if (arena->checks >= MAX_CHECKS)
	{
		arena->cycles_to_die -= CYCLE_DELTA;
		arena->checks = 0;
	}
	return (YES);
}

static void		check_cycles(t_func *f, t_arena *arena, int cycles, int counter)
{
	t_champ	*champ;

	champ = arena->champs;
	while (arena->alive)
	{
		if (cycles == arena->dump && arena->dump > 0)
		{
			dump_memory(arena);
			break ;
		}
		process_instruction(champ, arena, f);
		champ = champ->next;
		if (!champ)
		{
			counter++;
			cycles++;
			if (counter >= arena->cycles_to_die)
			{
				arena->alive = check_alive(arena);
				counter = 0;
			}
			if (!(champ = arena->champs))
				break ;
		}
	}
}

void			run_cycles(t_arena *arena)
{
	t_func	*f;
	int		counter;
	int		cycles;

	counter = 0;
	cycles = 0;
	if (!(f = (t_func*)malloc(sizeof(t_func) * 16)))
		return ;
	fill_functions(f);
	arena->alive = YES;
	check_cycles(f, arena, cycles, counter);
	free(f);
}
