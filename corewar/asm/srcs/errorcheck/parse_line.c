/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:27:10 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:27:12 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label			*parse_line(int fd, char **file)
{
	t_label *label;
	char	*line;
	int		i;

	label = NULL;
	line = NULL;
	while (!(i = 0) && get_next_line(fd, &line) > 0)
	{
		g_line++;
		while (line[i] == '\t' || line[i] == ' ')
			i++;
		if (line[i] && line[i] != COM_CHAR && line[i] != ';' &&
				check_label(line) >= 1)
		{
			label = label_init(label, line);
			while (line[i] != LBL_CHAR)
				i++;
			i++;
		}
		*file = put_line_in_file(line, i, *file);
	}
	return (label);
}
