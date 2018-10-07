/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 08:29:18 by jngoma            #+#    #+#             */
/*   Updated: 2017/10/26 14:11:15 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int	ft_is_label_only(char *line)
{
	char	**split;

	if (ft_strchr(line, LABEL_CHAR))
	{
		split = ft_strsplit(line, LABEL_CHAR);
		if (ft_items_in_grid((void **)split) == 1)
		{
			ft_destroy_2d((void **)split);
			return (1);
		}
		else
		{
			ft_destroy_2d((void **)split);
			return (0);
		}
	}
	else
		return (0);
}

int	ft_contains_label(char *line)
{
	char	**split;

	split = ft_strsplit(line, ' ');
	if (ft_strchr(split[0], LABEL_CHAR))
	{
		ft_destroy_2d((void **)split);
		return (1);
	}
	ft_destroy_2d((void **)split);
	return (0);
}
