/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 17:27:37 by gtshekel          #+#    #+#             */
/*   Updated: 2017/08/29 11:49:22 by pamashil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int		ft_zjmp(t_conv **ins, int t_bytes, t_lbl *lbls)
{
	char	**split;
	char	*defix;

	defix = ft_strdefix((*ins)->line, ' ');
	if (!(split = ft_strsplit(defix, SEPARATOR_CHAR)))
		return (0);
	if (!((*ins)->opcode = ft_get_opcode("zjmp")))
		return (0);
	(*ins)->bytes = 3;
	(*ins)->hasencoding = 0;
	(*ins)->n_params = 1;
	(*ins)->index = t_bytes + 1;
	(*ins)->dir_bytes = IND_SIZE;
	(*ins)->indir_bytes = IND_SIZE;
	ft_decoding(ins);
	fill_params(ins, split, lbls);
	ft_destroy_2d((void**)split);
	free(defix);
	return (1);
}
