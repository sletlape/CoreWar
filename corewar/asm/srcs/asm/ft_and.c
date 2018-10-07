/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 14:15:02 by jbadenho          #+#    #+#             */
/*   Updated: 2017/09/13 16:09:09 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int	ft_and(t_conv **ins, int t_bytes, t_lbl *labels)
{
	char	**split;
	char	*defix;
	int		i;

	if (!(defix = ft_strdefix((*ins)->line, ' ')) ||
			!(split = ft_strsplit(defix, ',')))
		return (0);
	if (!((*ins)->opcode = ft_get_opcode("and")))
		return (0);
	(*ins)->bytes = 2;
	(*ins)->hasencoding = 1;
	(*ins)->encoding = ft_get_encoding((*ins)->line);
	(*ins)->n_params = 3;
	(*ins)->indir_bytes = IND_SIZE;
	(*ins)->dir_bytes = DIR_SIZE;
	(*ins)->index = t_bytes + 1;
	ft_decoding(ins);
	fill_params(ins, split, labels);
	i = -1;
	while (++i < (*ins)->n_params)
		(*ins)->bytes += (*ins)->b_param[i];
	ft_destroy_2d((void**)split);
	ft_strdel(&defix);
	return (1);
}
