/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:27:16 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:27:17 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_hdr	*save_header(char *line, t_hdr *head, int check)
{
	char *tmp;

	tmp = NULL;
	if (check == 0)
	{
		tmp = ft_strsub(line, 0, ft_strclen(line, '"'));
		ft_strncat(head->prog_name, tmp, PROG_NAME_LENGTH);
	}
	if (check == 1)
	{
		if (line[0] == '"')
			ft_strcpy(head->comment, "Commentless champion");
		else
		{
			tmp = ft_strsub(line, 0, ft_strclen(line, '"'));
			ft_strncat(head->comment, tmp, COM_LENGTH);
		}
	}
	if (tmp != NULL)
		free(tmp);
	tmp = NULL;
	return (head);
}
