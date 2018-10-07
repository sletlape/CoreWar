/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsebaets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 09:32:02 by gsebaets          #+#    #+#             */
/*   Updated: 2017/09/26 08:27:06 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int		ft_aff(t_conv **instruct, int t_bytes, t_lbl *labels)
{
	char	*defix;
	char	**split;

	if (!(defix = ft_strdefix((*instruct)->line, ' ')) ||
			!(split = ft_strsplit(defix, ',')))
		return (0);
	if (!((*instruct)->opcode = ft_get_opcode("aff")))
		return (0);
	(*instruct)->bytes = 3;
	(*instruct)->hasencoding = 1;
	(*instruct)->encoding = ft_get_encoding((*instruct)->line);
	(*instruct)->n_params = 1;
	(*instruct)->index = t_bytes + 1;
	(*instruct)->indir_bytes = 1;
	(*instruct)->dir_bytes = 2;
	ft_decoding(instruct);
	fill_params(instruct, split, labels);
	(*instruct)->b_param[0] = 1;
	return (1);
}
