/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:26:02 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:26:03 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			check_arg(char **line, int op)
{
	while (**line == ' ' || **line == '\t')
		(*line)++;
	if ((op == LIVE || op == ZJMP || op == FORK || op == LFORK) &&
			check_direct(line, op, 0))
		return (1);
	if ((op == LD || op == LLD) && (check_direct(line, op, 1) ||
				check_indirect(line, 1)) && check_register(line, 0))
		return (1);
	if ((op == AND || op == OR || op == XOR) && ((check_direct(line, op, 1) ||
					check_register(line, 1) || check_indirect(line, 1))
				&& (check_direct(line, op, 1) || check_register(line, 1) ||
					check_indirect(line, 1)) && check_register(line, 0)))
		return (1);
	if (op == STI && check_register(line, 1) && (check_direct(line, op, 1) ||
				check_register(line, 1) || check_indirect(line, 1)) &&
			(check_direct(line, op, 0) || check_register(line, 0)))
		return (1);
	if (op == AFF && check_register(line, 0))
		return (1);
	return (check_arg_sec(line, op));
}
