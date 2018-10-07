/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 09:32:02 by mmayibo           #+#    #+#             */
/*   Updated: 2017/08/28 16:30:30 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int		ft_live(t_conv **instruct, int t_bytes, t_lbl *lbls)
{
	char	*defix;
	char	**split;

	if (!(defix = ft_strdefix((*instruct)->line, ' ')) ||
			!(split = ft_strsplit(defix, ',')))
		return (0);
	if (!((*instruct)->opcode = ft_get_opcode("live")))
		return (0);
	(*instruct)->bytes = 5;
	(*instruct)->hasencoding = 0;
	(*instruct)->n_params = 1;
	(*instruct)->index = t_bytes + 1;
	(*instruct)->indir_bytes = IND_SIZE;
	(*instruct)->dir_bytes = DIR_SIZE;
	ft_decoding(instruct);
	fill_params(instruct, split, lbls);
	ft_destroy_2d((void**)split);
	free(defix);
	return (1);
}
