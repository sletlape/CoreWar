/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_indirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:26:17 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:26:18 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			check_indirect(char **line, int check)
{
	if (**line == LBL_CHAR)
	{
		(*line)++;
		while (**line && ft_strchr(LBL_CHARS, **line))
			(*line)++;
	}
	else if (((**line == '+' || **line == '-') && (*line)++) ||
			ft_isdigit(**line))
	{
		while (ft_isdigit(**line))
			(*line)++;
	}
	else
		return (0);
	if (**line != '\0' && **line != '\n'
			&& **line != SEPARATOR_CHAR && **line != ' ' && **line != '\t')
		return (asm_error(INDIRECT_ERROR));
	g_pos = g_pos + 2;
	if (check == 1)
		return (check_comma(line));
	return (1);
}
