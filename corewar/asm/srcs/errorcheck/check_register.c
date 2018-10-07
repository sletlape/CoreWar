/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_register.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:26:25 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:26:26 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			check_register(char **line, int check)
{
	int reg;

	reg = 0;
	if (**line == 'r')
	{
		(*line)++;
		reg = ft_atoi(*line);
		if (reg > REG_NUMBER || reg <= 0)
			return (asm_error(REG_ERROR));
		(*line)++;
		if (reg > 9)
			(*line)++;
		if (reg > 99)
			(*line)++;
		g_pos++;
		if (check == 1)
			return (check_comma(line));
		return (1);
	}
	return (0);
}
