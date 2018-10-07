/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:26:15 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:26:16 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_header(t_hdr *head, char *line)
{
	if (head->comment[0] && head->prog_name[0])
	{
		if (ft_strrchr(line, '"') != ft_strchr(line, '"'))
		{
			free(line);
			line = NULL;
			return (1);
		}
		return (asm_error(LINES_ERROR));
	}
	return (0);
}
