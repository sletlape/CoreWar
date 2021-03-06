/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:26:26 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:26:28 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Increment upon instruction's length
*/

int			check_valid_line(char *line)
{
	int fct;

	fct = asm_instruct_name(line);
	if (fct)
		g_pos++;
	if (fct == LIVE || fct == ZJMP || fct == FORK || fct == LLDI)
		line = line + 4;
	else if (fct == LD || fct == ST || fct == OR)
		line = line + 2;
	else if (fct == LFORK)
		line = line + 5;
	else
		line = line + 3;
	if (fct != LIVE && fct != ZJMP && fct != FORK && fct != LFORK)
		g_pos++;
	check_arg(&line, fct);
	while (*line && *line != '\n' && *line != COM_CHAR && *line != ';')
		if (*line && *line != ' ' && *line != '\t' && *line != '\n')
			return (asm_error(ARG_ERROR));
		else
			line++;
	return (1);
}
