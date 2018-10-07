/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 08:29:18 by jngoma            #+#    #+#             */
/*   Updated: 2017/10/26 14:08:25 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

t_lbl		*create_label(char **line, int t_bytes)
{
	t_lbl		*lbl;
	char		**split;
	char		*tmp;
	int			lbl_len;

	if (!(lbl = (t_lbl*)malloc(sizeof(t_lbl))))
		return (NULL);
	split = ft_strsplit(*line, LABEL_CHAR);
	lbl->name = ft_strdup(split[0]);
	lbl->index = t_bytes + 1;
	lbl->next = NULL;
	lbl_len = ft_strlen(lbl->name);
	tmp = ft_strdup(*line);
	free(*line);
	*line = ft_strsub(tmp, lbl_len + 1, ft_strlen(tmp) - lbl_len - 1);
	free(tmp);
	tmp = ft_strtrim(*line);
	free(*line);
	*line = tmp;
	ft_destroy_2d((void **)split);
	return (lbl);
}

void		add_label(t_lbl **lbl, t_lbl *new_lbl)
{
	new_lbl->next = *lbl;
	*lbl = new_lbl;
}

int			needslabel(char *param)
{
	if (ft_strchr(param, LABEL_CHAR))
		return (1);
	return (0);
}

int			get_lbl(char *item, int index, t_lbl *lbls)
{
	char	**split;
	int		num;
	t_lbl	*tmp;

	tmp = lbls;
	split = ft_strsplit(item, LABEL_CHAR);
	num = ft_items_in_grid((void**)split);
	while (tmp)
	{
		if ((ft_strequ(tmp->name, split[num == 1 ? 0 : 1])))
		{
			ft_destroy_2d((void**)split);
			return (tmp->index - index);
		}
		tmp = tmp->next;
	}
	ft_destroy_2d((void**)split);
	return (index);
}

void		create_all_lbls(t_lbl **lbls, t_conv **data, int t_bytes)
{
	t_conv	*ins;

	ins = *data;
	while (ins)
	{
		if (ft_is_label_only(ins->line) || ft_contains_label(ins->line))
		{
			if (*lbls == NULL)
				*lbls = create_label(&ins->line, t_bytes);
			else
				add_label(lbls, create_label(&ins->line, t_bytes));
		}
		if (ins->line && ft_strlen(ins->line) > 0)
			t_bytes += get_bytes_in_line(ins->line, 0);
		ins = ins->next;
	}
}
