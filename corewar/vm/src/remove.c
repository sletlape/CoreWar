/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 09:44:56 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/23 09:57:29 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static void	remove_player(int id, t_champ **head)
{
	t_champ	*temp;
	t_champ	*prev;

	temp = (*head);
	if (temp->id == id)
	{
		(*head) = temp->next;
		free(temp);
		return ;
	}
	prev = temp;
	temp = temp->next;
	while (temp)
	{
		if (temp->id == id)
		{
			prev->next = temp->next;
			temp->prev = prev->prev;
			free(temp);
			break ;
		}
		prev = temp;
		temp = temp->next;
	}
}

int			check_player(t_arena *arena)
{
	t_champ	*champ;
	t_champ	*prev;
	int		max_lives;

	champ = arena->champs;
	max_lives = 0;
	while (champ)
	{
		prev = champ;
		max_lives += champ->alive;
		champ = champ->next;
		if (!prev->alive)
			remove_player(prev->id, &(arena->champs));
		else
			prev->alive = 0;
	}
	return (max_lives);
}
