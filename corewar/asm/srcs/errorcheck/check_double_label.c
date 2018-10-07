/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_label.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:26:13 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:26:14 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				check_double_label(t_label *label)
{
	t_label *start;

	start = label;
	if (!label)
		return (1);
	label = label->next;
	while (label)
	{
		if (ft_strcmp(start->name, label->name) == 0)
			return (asm_error(LBLS_DOUBLE_ERROR));
		label = label->next;
	}
	return (check_double_label(start->next));
}
