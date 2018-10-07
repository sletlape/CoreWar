/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_sec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:26:06 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:26:07 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	check_arg_sec(char **line, int op)
{
	if (op == ST && check_register(line, 1) && (check_indirect(line, 0) ||
				check_register(line, 0)))
		return (1);
	if ((op == ADD || op == SUB) && check_register(line, 1) &&
			check_register(line, 1) && check_register(line, 0))
		return (1);
	if ((op == LDI || op == LLDI) && (check_direct(line, op, 1) ||
				check_register(line, 1) || check_indirect(line, 1)) &&
			(check_direct(line, op, 1) || check_register(line, 1)) &&
			check_register(line, 0))
		return (1);
	return (asm_error(ARGS_ERROR));
}
