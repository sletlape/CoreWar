/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label_exist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:26:23 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:26:24 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				check_label_exist(t_label *label, char *str)
{
	int len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != DIRECT_CHAR)
	{
		len++;
		if (str[len] == DIRECT_CHAR)
		{
			len++;
			if (str[len] == LBL_CHAR)
			{
				len++;
				match_label(label, &str[len]);
			}
		}
	}
	return (1);
}
