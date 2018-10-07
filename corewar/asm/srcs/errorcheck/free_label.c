/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:26:31 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:26:32 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		free_label(t_label *label)
{
	t_label *nxt;

	nxt = label->next;
	while (nxt)
	{
		label->next = NULL;
		free(label->name);
		free(label);
		label = nxt;
		nxt = label->next;
	}
	free(label->name);
	free(label);
	return (1);
}
