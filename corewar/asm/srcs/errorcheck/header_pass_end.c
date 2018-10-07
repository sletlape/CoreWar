/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_pass_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:26:39 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:26:40 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		header_pass_end(char *line, int i)
{
	while (line[i] && line[i] != '"')
		i++;
	if (line[i] == '"')
		i++;
	while (line[i] && line[i] != '\n' && i++)
		if (line[i] && line[i] != ' ' && line[i] != '\t')
			return (asm_error(FORMAT_ERROR));
	return (0);
}
