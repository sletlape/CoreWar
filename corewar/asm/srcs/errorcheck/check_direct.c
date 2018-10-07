/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_direct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:26:11 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:26:12 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			check_direct(char **line, int op, int check)
{
	if (**line == DIRECT_CHAR)
	{
		if (op > 8 && op != 13)
			g_pos = g_pos + 2;
		else
			g_pos = g_pos + 4;
		(*line)++;
		if (**line != LBL_CHAR && !(**line >= '0' && **line <= '9') &&
				**line != '-' && **line != '+')
			asm_error(LBL_ERROR);
		if (**line == LBL_CHAR)
			(*line)++;
		else if (**line == '+' || **line == '-')
			(*line)++;
		while (**line && ft_strchr(LBL_CHARS, **line))
			(*line)++;
		while (**line == ' ' || **line == '\t')
			(*line)++;
		if (check == 1)
			return (check_comma(line));
		return (1);
	}
	return (0);
}
