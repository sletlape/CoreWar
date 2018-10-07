/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:25:51 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:25:52 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_error(int error)
{
	if (error == FORMAT_ERROR)
		ft_printf_fd(2, "Wrong format name -> line: %d\n", g_line);
	if (error == LBLS_ERROR)
		ft_printf_fd(2, "Wrong labels_char -> line: %d\n", g_line);
	if (error == LBL_CHAR_ERROR)
		ft_printf_fd(2, "Wrong format name -> line: %d\n", g_line);
	if (error == INSTRUCT_ERROR)
		ft_printf_fd(2, "Wrong name of instruct -> line: %d\n", g_line);
	if (error == INDIRECT_ERROR)
		ft_printf_fd(2, "Not an indirect -> line: %d\n", g_line);
	if (error == ARGS_ERROR)
		ft_printf_fd(2, "Arguments problems -> line: %d\n", g_line);
	if (error == LBLS_DOUBLE_ERROR)
		ft_printf_fd(2, "Label double -> line: %d\n", g_line);
	if (error == LBL_MATCH_ERROR)
		ft_printf_fd(2, "Label doesn't match -> line: %d\n", g_line);
	return (asm_error_sec(error));
}
