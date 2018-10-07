/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:36:42 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/19 11:37:48 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

void	ft_lfork(int pc, t_arena *arena, t_champ *champ)
{
	int				value[3];
	t_champ			*dup;

	if (inititate_wait(champ, arena, 999, "LFORK"))
		return ;
	champ->run = NO;
	pc++;
	value[0] = get_one_value(IND_SIZE, pc, arena->arena, champ);
	if (!(dup = (t_champ *)ft_memdup((const unsigned char*)champ,
			sizeof(t_champ))))
		exit_prog("malloc error, cant fork process", arena);
	dup->next = NULL;
	dup->pc = (dup->pc + value[0]) % MEM_SIZE;
	add_champ(&(arena->champs), dup);
	champ->pc = (champ->pc + IND_SIZE + 1) % MEM_SIZE;
	show_trace("\nLFORK played by : ", arena, champ, SHOW_ALL_CHAMPS);
}
