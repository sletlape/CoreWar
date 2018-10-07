/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error_sec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:25:53 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:25:54 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_error_sec(int error)
{
	if (error == NAME_ERROR)
		ft_printf_fd(2, "Impossible to find name or comment\n");
	if (error == ARG_ERROR)
		ft_printf_fd(2, "Argument error for instruction -> line %d\n", g_line);
	if (error == LINES_ERROR)
		ft_printf_fd(2, "Error multiple lines on name or comment\n");
	if (error == FILE_ERROR)
		ft_printf_fd(2, "Wrong file extension\n");
	if (error == LBL_ERROR)
		ft_printf_fd(2, "Label Char error\n");
	if (error == MALLOC_ERROR)
		ft_printf_fd(2, "Malloc probs");
	if (error == REG_ERROR)
		ft_printf_fd(2, "Register troubles -> line: %d\n", g_line);
	if (error == CHAMPION_ERROR)
		ft_printf_fd(2, "Usage: champion.s\n");
	g_error = 1;
	exit(0);
	return (0);
}
