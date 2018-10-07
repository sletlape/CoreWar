/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 09:32:02 by mmayibo           #+#    #+#             */
/*   Updated: 2017/09/13 16:52:07 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int		ft_sti(t_conv **instruct, int t_bytes, t_lbl *lbls)
{
	char	*defix;
	char	**split;
	int		i;

	if (!(defix = ft_strdefix((*instruct)->line, ' ')) ||
			!(split = ft_strsplit(defix, ',')))
		return (0);
	if (!((*instruct)->opcode = ft_get_opcode("sti")))
		return (0);
	(*instruct)->bytes = 2;
	(*instruct)->hasencoding = 1;
	(*instruct)->encoding = ft_get_encoding((*instruct)->line);
	(*instruct)->n_params = 3;
	(*instruct)->index = t_bytes + 1;
	(*instruct)->indir_bytes = IND_SIZE;
	(*instruct)->dir_bytes = IND_SIZE;
	ft_decoding(instruct);
	fill_params(instruct, split, lbls);
	i = -1;
	while (++i < (*instruct)->n_params)
		(*instruct)->bytes += (*instruct)->b_param[i];
	ft_destroy_2d((void**)split);
	free(defix);
	return (1);
}
