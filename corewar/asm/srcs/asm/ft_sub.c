/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:38:11 by amatshiy          #+#    #+#             */
/*   Updated: 2017/08/31 14:42:55 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int	ft_sub(t_conv **ins, int t_bytes, t_lbl *lbls)
{
	char	**split;
	char	*defix;
	int		i;

	defix = ft_strdefix((*ins)->line, ' ');
	if (!(split = ft_strsplit(defix, SEPARATOR_CHAR)))
		return (0);
	if (!((*ins)->opcode = ft_get_opcode("sub")))
		return (0);
	(*ins)->bytes = 2;
	(*ins)->hasencoding = 1;
	(*ins)->encoding = ft_get_encoding((*ins)->line);
	(*ins)->n_params = 3;
	ft_decoding(ins);
	(*ins)->index = t_bytes + 1;
	fill_params(ins, split, lbls);
	i = -1;
	while (++i < (*ins)->n_params)
		(*ins)->bytes += (*ins)->b_param[i];
	ft_destroy_2d((void**)split);
	free(defix);
	return (1);
}
