/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:27:02 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:27:05 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		match_label(t_label *label, char *str)
{
	int i;

	i = 0;
	while (ft_strchr(LBL_CHARS, str[i]))
		i++;
	while (label)
	{
		if (ft_strncmp(label->name, str, i) == 0)
		{
			if (!label->name[i])
				return (1);
		}
		label = label->next;
	}
	return (asm_error(LBL_MATCH_ERROR));
}
