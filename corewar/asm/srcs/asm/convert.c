/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 10:30:52 by akhanye           #+#    #+#             */
/*   Updated: 2017/09/26 08:20:53 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int		init_struct(t_conv *temp, char **line)
{
	int	i;

	i = -1;
	if (!(temp->line = ft_strtrim(*line)))
		return (0);
	temp->index = 0;
	temp->bytes = 0;
	temp->haslabel = 0;
	temp->opcode = 0;
	temp->hasencoding = 0;
	temp->encoding = 0;
	temp->n_params = 0;
	temp->next = NULL;
	temp->dir_bytes = 0;
	temp->indir_bytes = 0;
	i = -1;
	while (++i < 3)
	{
		temp->b_param[i] = 0;
		temp->param[i] = 0;
		temp->param_types[i] = 0;
	}
	return (1);
}

int		count_all_bytes(t_asm *data)
{
	int		b;
	t_conv	*iter;

	b = 0;
	if (!data->line)
		return (b);
	iter = data->line;
	while (iter)
	{
		b += iter->bytes;
		iter = iter->next;
	}
	return (b);
}

void	cut_off_comment(char **line)
{
	char	**split;

	if (ft_strchr(*line, COMMENT_CHAR))
	{
		split = ft_strsplit(*line, COMMENT_CHAR);
		ft_strdel(line);
		*line = ft_strdup(split[0]);
		ft_destroy_2d((void**)split);
	}
	else if (ft_strchr(*line, ';'))
	{
		split = ft_strsplit(*line, ';');
		ft_strdel(line);
		*line = ft_strdup(split[0]);
		ft_destroy_2d((void**)split);
	}
}

void	get_string(char *str, char *line)
{
	int		index;
	int		index2;

	index = 0;
	index2 = 0;
	while (line[index] && line[index] != '"')
		index++;
	if (line[index] == '"')
		index++;
	while (line[index] && line[index] != '"')
		str[index2++] = line[index++];
}

int		add_line(t_conv **data, char **line)
{
	t_conv	*temp;
	t_conv	*iter;

	if (!(temp = (t_conv*)malloc(sizeof(t_conv))))
		return (0);
	if (!init_struct(temp, line))
		return (0);
	if (!(*data))
		(*data) = temp;
	else
	{
		iter = (*data);
		while (iter->next)
			iter = iter->next;
		iter->next = temp;
	}
	return (1);
}
