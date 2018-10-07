/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamashil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 11:02:53 by pamashil          #+#    #+#             */
/*   Updated: 2017/09/05 09:29:38 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int	ft_fork(t_conv **ins, int t_bytes, t_lbl *lbls)
{
	char	**split;
	char	*defix;

	defix = ft_strdefix((*ins)->line, ' ');
	if (!(split = ft_strsplit(defix, SEPARATOR_CHAR)))
		return (0);
	if (!((*ins)->opcode = ft_get_opcode("fork")))
		return (0);
	(*ins)->bytes = 3;
	(*ins)->hasencoding = 0;
	(*ins)->n_params = 1;
	(*ins)->index = t_bytes + 1;
	(*ins)->dir_bytes = T_DIR;
	(*ins)->indir_bytes = T_DIR;
	ft_decoding(ins);
	fill_params(ins, split, lbls);
	ft_destroy_2d((void**)split);
	free(defix);
	return (1);
}
