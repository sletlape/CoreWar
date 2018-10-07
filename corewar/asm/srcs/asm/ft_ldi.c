/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 10:45:51 by gtshekel          #+#    #+#             */
/*   Updated: 2017/09/26 08:37:04 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int		ft_ldi(t_conv **ins, int t_bytes, t_lbl *lbls)
{
	char	**split;
	char	*defix;
	int		i;

	if (!(defix = ft_strdefix((*ins)->line, ' ')) ||
			!(split = ft_strsplit(defix, ',')))
		return (0);
	if (!((*ins)->opcode = ft_get_opcode("ldi")))
		return (0);
	(*ins)->bytes = 2;
	(*ins)->hasencoding = 1;
	(*ins)->encoding = ft_get_encoding((*ins)->line);
	(*ins)->n_params = 3;
	(*ins)->index = t_bytes + 1;
	(*ins)->indir_bytes = IND_SIZE;
	(*ins)->dir_bytes = IND_SIZE;
	ft_decoding(ins);
	fill_params(ins, split, lbls);
	i = -1;
	while (++i < (*ins)->n_params)
		(*ins)->bytes += (*ins)->b_param[i];
	ft_destroy_2d((void**)split);
	ft_strdel(&defix);
	return (1);
}
