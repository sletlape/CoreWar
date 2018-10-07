/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 21:04:42 by akhanye           #+#    #+#             */
/*   Updated: 2017/09/26 08:40:46 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int				main(int ac, char **av)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = 0;
	line = NULL;
	while (++count < ac)
	{
		if (!ft_fileok(av[count]))
			return (0);
		if (!(fd = open(av[count], O_RDONLY, 0555)))
			return (0);
		ft_putstr("Assembling ");
		ft_putendl(av[count]);
		if (!convert_file(fd, av[count], line))
			ft_putstr("Error converting file\n");
		close(fd);
	}
	return (0);
}
