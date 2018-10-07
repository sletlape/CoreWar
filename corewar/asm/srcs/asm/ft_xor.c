/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 14:15:57 by jbadenho          #+#    #+#             */
/*   Updated: 2017/09/13 16:04:54 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int	ft_xor(t_conv **ins, int t_bytes, t_lbl *lbls)
{
	char	**split;
	char	*defix;
	int		i;

	if (!(defix = ft_strdefix((*ins)->line, ' ')) ||
			!(split = ft_strsplit(defix, ',')))
		return (0);
	if (!((*ins)->opcode = ft_get_opcode("xor")))
		return (0);
	(*ins)->bytes = 2;
	(*ins)->hasencoding = 1;
	(*ins)->encoding = ft_get_encoding((*ins)->line);
	(*ins)->n_params = 3;
	(*ins)->index = t_bytes + 1;
	(*ins)->indir_bytes = IND_SIZE;
	(*ins)->dir_bytes = DIR_SIZE;
	ft_decoding(ins);
	fill_params(ins, split, lbls);
	i = -1;
	while (++i < (*ins)->n_params)
		(*ins)->bytes += (*ins)->b_param[i];
	ft_destroy_2d((void**)split);
	ft_strdel(&defix);
	return (1);
}
