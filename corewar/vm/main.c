/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 12:26:02 by mmayibo           #+#    #+#             */
/*   Updated: 2017/09/20 11:11:10 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				exit_prog(char *mess, t_arena *arena)
{
	t_champ	*fr;
	t_champ	*temp;

	if (mess)
		ft_putendl(mess);
	if (arena)
	{
		if (arena->champs)
		{
			temp = arena->champs;
			while (temp)
			{
				fr = temp;
				temp = temp->next;
				free(fr);
			}
		}
		free(arena);
	}
	exit(0);
}

static void		init_arena_local(t_arena *arena)
{
	int	i;

	i = -1;
	arena->dump = 0;
	arena->number = 0;
	ft_bzero((char*)arena->arena, MEM_SIZE);
	arena->cycles_to_die = CYCLE_TO_DIE;
	arena->players = 0;
	arena->champs = NULL;
	arena->checks = 0;
	arena->visual = 0;
	while (++i < MAX_PLAYERS)
		arena->fd[i] = -1;
}

static void		print_winner(t_arena *arena)
{
	ft_putstr("\nPlayer ");
	ft_putnbr(arena->last_live);
	ft_putstr(" (");
	ft_putstr(arena->p_name);
	ft_putstr(") won\n\t");
	ft_putendl(arena->p_com);
}

int				main(int ac, char **av)
{
	char	err[MAX_ERROR];
	t_arena	*arena;

	if (ac < 2)
	{
		exit_prog(
				"./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...",
				NULL);
	}
	if (!(arena = (t_arena*)malloc(sizeof(t_arena))))
		return (0);
	init_arena_local(arena);
	if (!get_options(ac, av, err, arena))
		exit_prog(err, arena);
	get_fds(ac, av, arena);
	read_champs(arena);
	fill_arena(arena);
	run_cycles(arena);
	if (!arena->dump)
		print_winner(arena);
	exit_prog(NULL, arena);
	return (0);
}
