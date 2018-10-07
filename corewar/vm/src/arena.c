/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:53:08 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/19 12:10:04 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void			init_arena(t_arena *arena)
{
	arena->number = 1;
	arena->dump = 0;
	arena->trace = FALSE;
	arena->champs = NULL;
	arena->last_live = 0;
}

void			dump_memory(t_arena *arena)
{
	int		i;
	char	line;

	i = -1;
	ft_putline();
	while (++i < MEM_SIZE)
	{
		if (!(i % 32) && i > 0)
			ft_putchar('\n');
		else if (i > 0 && (i % 32))
			ft_putchar(' ');
		if (!(i % 32))
		{
			line = (i / 32) % 255;
			ft_putstr("0x");
			if (line < 16)
				ft_putchar('0');
			ft_printhex(line);
			ft_putstr(" : ");
		}
		if (arena->arena[i] < 16)
			ft_putchar('0');
		ft_printhex(arena->arena[i]);
	}
	ft_putline();
}

void			fill_arena(t_arena *arena)
{
	int		i;
	int		dif;
	t_champ	*champ;
	int		max_size;
	int		start;

	dif = MEM_SIZE / arena->players;
	max_size = MEM_SIZE;
	i = -1;
	champ = arena->champs;
	while (++i < arena->players)
	{
		start = max_size - dif;
		if (start < 10 && start > 0 && arena->players == 3)
			start = 0;
		ft_memcpy((void*)arena->arena + start,
				(const void*)champ->prog, champ->player_size);
		champ->pc = start;
		champ = champ->next;
		max_size -= dif;
	}
}
