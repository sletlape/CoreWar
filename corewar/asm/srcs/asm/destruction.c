/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 08:21:39 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/26 08:23:24 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

void		destroy_labels(t_lbl *labels)
{
	t_lbl	*tmp;

	while (labels)
	{
		tmp = labels;
		labels = labels->next;
		free(tmp->name);
		tmp->name = NULL;
		free(tmp);
		tmp = NULL;
	}
}

void		destroy_data(t_conv *data)
{
	t_conv	*tmp;

	while (data)
	{
		tmp = data;
		data = data->next;
		ft_strdel(&tmp->line);
		free(tmp);
		tmp = NULL;
	}
}
