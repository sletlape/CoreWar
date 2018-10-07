/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 14:57:59 by ckatz             #+#    #+#             */
/*   Updated: 2017/09/13 16:01:28 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int			ft_st(t_conv **instruct, int t_bytes, t_lbl *lbls)
{
	char	*defix;
	char	**split;
	int		i;

	if (!(defix = ft_strdefix((*instruct)->line, ' ')) ||
			!(split = ft_strsplit(defix, ',')))
		return (0);
	if (!((*instruct)->opcode = ft_get_opcode("st")))
		return (0);
	(*instruct)->bytes = 2;
	(*instruct)->hasencoding = 1;
	(*instruct)->encoding = ft_get_encoding((*instruct)->line);
	(*instruct)->n_params = 2;
	(*instruct)->index = t_bytes + 1;
	(*instruct)->indir_bytes = IND_SIZE;
	ft_decoding(instruct);
	fill_params(instruct, split, lbls);
	i = -1;
	while (++i < (*instruct)->n_params)
		(*instruct)->bytes += (*instruct)->b_param[i];
	ft_destroy_2d((void**)split);
	ft_strdel(&defix);
	return (1);
}
