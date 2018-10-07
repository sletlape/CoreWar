/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:49:07 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/19 11:49:16 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

void	ft_zjmp(int pc, t_arena *arena, t_champ *champ)
{
	int				value[3];

	if (!champ->carry)
	{
		champ->pc += 3;
		return ;
	}
	if (inititate_wait(champ, arena, 19, "ZJMP"))
		return ;
	champ->run = NO;
	pc += 1;
	value[0] = get_one_value(DIR_CODE, pc, arena->arena, champ);
	champ->pc = (champ->pc + (value[0] % IDX_MOD)) % MEM_SIZE;
	show_trace("\nZJMP played by : ", arena, champ, SHOW_CHAMP);
}
