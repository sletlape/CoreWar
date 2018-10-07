/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:13:43 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/19 11:59:28 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static int	skip_options(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac && av[i] && av[i][0] == '-')
	{
		if (ft_strequ(av[i], "-t") || ft_strequ(av[i], "-trace"))
			i++;
		else
			i += 2;
	}
	return (i);
}

static void	get_fd(char *player, int *fd, t_arena *arena)
{
	char	temp[MAX_ERROR];

	if ((*fd = open(player, O_RDONLY)) == -1)
	{
		combine_error(temp, "error loading player : ", player);
		exit_prog(temp, arena);
	}
}

char		get_fds(int ac, char **av, t_arena *arena)
{
	int		i;
	int		n;
	char	temp[MAX_ERROR];

	i = -1;
	while (++i < MAX_PLAYERS)
		arena->fd[i] = -1;
	i = skip_options(ac, av);
	if (ac - i > MAX_PLAYERS)
		exit_prog("vm can load to a maximum of 4 champions", arena);
	arena->players = ac - i;
	n = -1;
	i--;
	while (++i < ac && av[i])
	{
		if (ft_strequ(av[i] + ft_strlen(av[i]) - 4, ".cor"))
			get_fd(av[i], &(arena->fd[++n]), arena);
		else
		{
			combine_error(temp, av[i], " invalid file format");
			exit_prog(temp, arena);
		}
	}
	return (TRUE);
}
