/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:37:55 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/19 11:38:57 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

static void	print_alive(int val, t_champ *temp)
{
	ft_putstr("A process shows that player ");
	ft_putnbr(val);
	ft_putstr(" (");
	ft_putstr(temp->name);
	ft_putstr(") is alive\n");
}

static void	register_live(t_arena *arena, int val,
		t_champ **head, t_champ *champ)
{
	t_champ *temp;

	if (!(temp = (*head)))
		return ;
	while (temp)
	{
		if (temp->playerno == val && temp->id == champ->id)
		{
			ft_strcpy(arena->p_name, temp->name);
			ft_strcpy(arena->p_com, temp->comment);
			temp->alive++;
			arena->last_live = val;
			if (!arena->visual)
				print_alive(val, temp);
			break ;
		}
		temp = temp->next;
	}
}

void		ft_live(int pc, t_arena *arena, t_champ *champ)
{
	int				value[3];
	int				bytes;

	if (inititate_wait(champ, arena, 9, "LIVE"))
		return ;
	champ->run = NO;
	pc += 1;
	value[0] = get_one_value(REG_SIZE, pc, arena->arena, champ);
	bytes = 5;
	champ->pc = (champ->pc + bytes) % MEM_SIZE;
	show_trace("\nLIVE played by : ", arena, champ, SHOW_CHAMP);
	register_live(arena, value[0], &(arena->champs), champ);
}
