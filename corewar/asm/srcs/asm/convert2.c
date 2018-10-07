/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 10:30:52 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/26 14:27:30 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int				get_file(int fd, t_asm *data, char *line)
{
	char	**split;

	data->header.magic = 0xea83f3;
	ft_bzero(data->header.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(data->header.comment, COMMENT_LENGTH + 1);
	data->header.prog_size = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ft_replace(&line, '\t', ' ');
		split = ft_strsplit(line, ' ');
		if (split[0] && !ft_strcmp(split[0], NAME_CMD_STRING))
			get_string(data->header.prog_name, line);
		else if (split[0] && !ft_strcmp(split[0], COMMENT_CMD_STRING))
			get_string(data->header.comment, line);
		else if (split[0] && split[0][0] != COMMENT_CHAR && split[0][0] != ';')
		{
			cut_off_comment(&line);
			add_line(&(data->line), &line);
		}
		ft_strdel(&line);
		ft_destroy_2d((void**)split);
	}
	ft_strdel(&line);
	return (1);
}

int				update(t_conv **line, int t_bytes, t_lbl *labels, t_fn *functs)
{
	char		*toiter;
	char		*mne;
	int			i;

	toiter = (*line)->line;
	i = -1;
	while (toiter[++i] != ' ' && toiter[i] != '\t')
		;
	mne = ft_strndup(toiter, i);
	functs[(int)ft_get_opcode(mne) - 1](line, t_bytes, labels);
	ft_strdel(&mne);
	return (0);
}

static void		line_iterate(t_conv *iter, int t_bytes, t_lbl *labels,
		t_fn *functs)
{
	while (iter)
	{
		remove_tabs(iter->line);
		if (iter->line && ft_strlen(iter->line))
		{
			update(&iter, t_bytes, labels, functs);
			if (ft_strlen(iter->line) > 0)
				t_bytes += iter->bytes;
		}
		iter = iter->next;
	}
}

int				convert_file(int fd, char *fn, char *line)
{
	t_asm		data;
	t_lbl		*labels;
	int			t_bytes;
	t_conv		*iter;
	t_fn		functs[16];

	t_bytes = 0;
	data.fn = fn;
	data.line = NULL;
	labels = NULL;
	if (!get_file(fd, &data, line))
		return (0);
	iter = data.line;
	create_all_lbls(&labels, &iter, t_bytes);
	iter = data.line;
	fill_opcode_array(functs);
	line_iterate(iter, t_bytes, labels, functs);
	data.header.prog_size = (unsigned int)count_all_bytes(&data);
	write_to_cor(&data);
	destroy_labels(labels);
	destroy_data(data.line);
	return (1);
}
