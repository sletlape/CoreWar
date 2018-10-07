/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:27:00 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:27:01 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label		*label_init(t_label *label, char *line)
{
	t_label		*new;
	int			len;

	len = 0;
	if (!(new = malloc(sizeof(t_label))))
		return (NULL);
	while (line[len] != LBL_CHAR)
		len++;
	new->name = NULL;
	new->next = NULL;
	new->pos = 0;
	new->name = ft_strsub(line, 0, len);
	new->pos = g_pos;
	new->next = label;
	return (new);
}
