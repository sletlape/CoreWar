/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:27:09 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 09:40:34 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			name_comment_handler(int fd, t_hdr *head)
{
	int		i;
	char	*line;

	i = 0;
	line = 0;
	while (get_next_line(fd, &line) > 0)
	{
		g_line++;
		if (line[0] != COM_CHAR && line[0] != ';' && line[0] != '\0')
		{
			while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
				i++;
			save_name_com(&line[i], head, ft_strlen(NAME_CMD_STR),
			ft_strlen(COM_CMD_STR));
			if (check_header(head, line) == 1)
				return (1);
		}
		free(line);
		line = NULL;
	}
	return (asm_error(NAME_ERROR));
}
