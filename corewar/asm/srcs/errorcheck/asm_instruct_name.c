/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_instruct_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:25:58 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:25:59 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Check if instructions is correct and return corresponding int
*/

int			asm_instruct_name(char *line)
{
	if (ft_strncmp("live", line, 4) == 0)
		return (LIVE);
	if (ft_strncmp("add", line, 3) == 0)
		return (ADD);
	if (ft_strncmp("sub", line, 3) == 0)
		return (SUB);
	if (ft_strncmp("and", line, 3) == 0)
		return (AND);
	if (ft_strncmp("or", line, 2) == 0)
		return (OR);
	if (ft_strncmp("xor", line, 3) == 0)
		return (XOR);
	if (ft_strncmp("zjmp", line, 4) == 0)
		return (ZJMP);
	if (ft_strncmp("sti", line, 3) == 0)
		return (STI);
	return (instruct_name_sec(line));
}
