/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decoding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 13:45:45 by jngoma            #+#    #+#             */
/*   Updated: 2017/10/26 13:36:49 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

static void	set_param(char *trmd, t_conv **inst, int *j)
{
	if (trmd[0] == 'r')
		(*inst)->param_types[++(*j)] = REG_CODE;
	else
		(*inst)->param_types[++(*j)] = (trmd[0] == DC) ? DIR_CODE : IND_CODE;
	free(trmd);
}

void		ft_decoding(t_conv **inst)
{
	int					index;
	int					j;
	char				**split;
	char				*trmd;

	index = 0;
	j = -1;
	if (!(trmd = ft_strtrim((*inst)->line)))
		return ;
	while ((*inst)->line[index] && (((*inst)->line[index] != ' ') &&
				((*inst)->line[index] != '\t')))
		index++;
	if (!(split = ft_strsplit(trmd + index, SEPARATOR_CHAR)))
		return ;
	free(trmd);
	index = -1;
	while (++index < (*inst)->n_params)
	{
		if (!(trmd = ft_strtrim(split[index])))
			return ;
		set_param(trmd, inst, &j);
	}
	ft_destroy_2d((void**)split);
}
