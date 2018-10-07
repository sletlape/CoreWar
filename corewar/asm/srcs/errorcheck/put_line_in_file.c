/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line_in_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:27:14 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:27:15 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*put_line_in_file(char *line, int i, char *file)
{
	while (line[i] == '\t' || line[i] == ' ')
		i++;
	if (line[i] && line[i] != COM_CHAR && line[i] != ';' &&
			check_valid_line(&line[i]))
		file = asm_free_join(&line[i], file);
	free(line);
	line = NULL;
	return (file);
}
