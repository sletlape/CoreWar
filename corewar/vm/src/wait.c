/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:13:03 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/19 12:13:31 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

char	inititate_wait(t_champ *champ, t_arena *arena, int wait, char *name)
{
	if (!champ->run)
	{
		if (arena->trace)
		{
			ft_putstr(champ->name);
			ft_putstr(" must wait for ");
			ft_putnbr(wait + 1);
			ft_putstr(" cycles : playing -> ");
			ft_putstr(name);
			ft_putline();
		}
		champ->wait = wait;
		champ->run = YES;
		return (YES);
	}
	if (arena->trace)
	{
		ft_putstr(champ->name);
		ft_putstr(" has waited for ");
		ft_putnbr(wait + 1);
		ft_putstr(" cycles and now playing ");
		ft_putstr(name);
		ft_putline();
	}
	return (NO);
}
