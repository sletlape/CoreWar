/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_pass.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:26:36 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 10:24:58 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		header_pass(char *line, int name, int com, int check)
{
	int	i;

	if (check)
		i = name;
	else
		i = com;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '"')
		return (0);
	i++;
	return (i);
}
