/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:10:10 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/19 12:10:49 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void		show_trace(char *message, t_arena *arena,
		t_champ *champ, char show_type)
{
	if (!arena->trace)
		return ;
	ft_putstr(message);
	ft_putstr(champ->name);
	ft_putstr(" | player no : ");
	ft_putnbr(champ->playerno);
	ft_putstr(" | ID ");
	ft_putnbr(champ->id);
	ft_putline();
	if (show_type == SHOW_CHAMP || show_type == SHOW_BOTH)
		show_one_champ(champ);
	if (show_type == SHOW_ARENA || show_type == SHOW_BOTH)
		dump_memory(arena);
	if (show_type == SHOW_ALL_CHAMPS)
		show_all_champs(&(arena->champs));
	ft_putstr("PC pos : ");
	ft_putnbr(champ->pc);
	ft_putline();
	ft_putstr("Next opcode : ");
	ft_putnbr(arena->arena[champ->pc]);
	ft_putline();
	getchar();
}
