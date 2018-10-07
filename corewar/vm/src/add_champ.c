/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_champ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 13:31:56 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/19 13:33:56 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void			add_champ(t_champ **head, t_champ *champ)
{
	if (!(*head))
		(*head) = champ;
	else
	{
		(*head)->prev = champ;
		champ->next = (*head);
		(*head) = champ;
	}
}
