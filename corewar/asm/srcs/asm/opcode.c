/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 13:30:27 by mmayibo           #+#    #+#             */
/*   Updated: 2017/10/26 13:32:10 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

uint8_t		check_sec_instructs(char *str)
{
	uint8_t	opcode;

	opcode = 0;
	if (ft_strequ(str, "zjmp"))
		opcode = 9;
	else if (ft_strequ(str, "ldi"))
		opcode = 10;
	else if (ft_strequ(str, "sti"))
		opcode = 11;
	else if (ft_strequ(str, "fork"))
		opcode = 12;
	else if (ft_strequ(str, "lld"))
		opcode = 13;
	else if (ft_strequ(str, "lldi"))
		opcode = 14;
	else if (ft_strequ(str, "lfork"))
		opcode = 15;
	else if (ft_strequ(str, "aff"))
		opcode = 16;
	return (opcode);
}

uint8_t		check_first_instructs(char *str)
{
	uint8_t	opcode;

	opcode = 0;
	if (ft_strequ(str, "live"))
		opcode = 1;
	else if (ft_strequ(str, "ld"))
		opcode = 2;
	else if (ft_strequ(str, "st"))
		opcode = 3;
	else if (ft_strequ(str, "add"))
		opcode = 4;
	else if (ft_strequ(str, "sub"))
		opcode = 5;
	else if (ft_strequ(str, "and"))
		opcode = 6;
	else if (ft_strequ(str, "or"))
		opcode = 7;
	else if (ft_strequ(str, "xor"))
		opcode = 8;
	return (opcode);
}

void		fill_opcode_array(t_fn *func_array)
{
	func_array[0] = ft_live;
	func_array[1] = ft_ld;
	func_array[2] = ft_st;
	func_array[3] = ft_add;
	func_array[4] = ft_sub;
	func_array[5] = ft_and;
	func_array[6] = ft_or;
	func_array[7] = ft_xor;
	func_array[8] = ft_zjmp;
	func_array[9] = ft_ldi;
	func_array[10] = ft_sti;
	func_array[11] = ft_fork;
	func_array[12] = ft_lld;
	func_array[13] = ft_lldi;
	func_array[14] = ft_lfork;
	func_array[15] = ft_aff;
}

uint8_t		ft_get_opcode(char *str)
{
	uint8_t opcode;

	if ((opcode = check_first_instructs(str)))
		return (opcode);
	opcode = check_sec_instructs(str);
	return (opcode);
}
