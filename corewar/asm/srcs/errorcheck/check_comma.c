/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comma.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:26:09 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:26:11 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	check_comma(char **line)
{
	while (**line == '\t' || **line == ' ')
		(*line)++;
	if (**line != SEPARATOR_CHAR)
		return (asm_error(ARGS_ERROR));
	(*line)++;
	while (**line == '\t' || **line == ' ')
		(*line)++;
	return (1);
}
