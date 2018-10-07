/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:30:32 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/19 11:30:36 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

void	ft_aff(int pc, t_arena *arena, t_champ *champ)
{
	int				value[3];
	int				bytes;

	if (inititate_wait(champ, arena, 1, "AFF"))
		return ;
	champ->run = NO;
	pc += 1;
	value[0] = get_one_value(T_REG, pc, arena->arena, champ);
	bytes = 3;
	champ->pc = (champ->pc + bytes) % MEM_SIZE;
	ft_putchar(value[0]);
	show_trace("\nAfter sti : played by : ", arena, champ, SHOW_CHAR);
}
