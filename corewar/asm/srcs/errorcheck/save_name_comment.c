/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_name_comment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:27:18 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:27:19 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			save_name_com(char *line, t_hdr *head, int name, int com)
{
	int		i;

	i = 0;
	if (!head->prog_name[0] && ft_strncmp(NAME_CMD_STR, line, name) == 0)
	{
		if ((i = header_pass(line, name, com, 1)) == 0)
			return (asm_error(FORMAT_ERROR));
		else
			save_header(&line[i], head, 0);
	}
	else if (!head->comment[0] &&
		ft_strncmp(COM_CMD_STR, line, com) == 0)
	{
		if ((i = header_pass(line, name, com, 0)) == 0)
			return (asm_error(NAME_ERROR));
		else
			head = save_header(&line[i], head, 1);
	}
	else
		return (asm_error(NAME_ERROR));
	return (header_pass_end(line, i));
}
