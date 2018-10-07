/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 12:57:54 by gtshekel          #+#    #+#             */
/*   Updated: 2017/08/24 14:11:05 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	**ft_destroy_2d(void **grid)
{
	int index;

	if (grid)
	{
		index = 0;
		while (grid[index])
		{
			ft_memdel(&grid[index]);
			index++;
		}
		free(grid);
		grid = NULL;
	}
	return (NULL);
}
