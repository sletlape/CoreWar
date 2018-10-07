/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:26:19 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:26:23 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				check_label(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] && ft_strchr(LBL_CHARS, str[i]))
		i++;
	if (str[i] == LBL_CHAR && i > 0)
	{
		i++;
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == '\n' || str[i] == '\0' || str[i] == COM_CHAR)
			return (1);
		return (2);
	}
	else if (str[i] && str[i] != ' ' && str[i] != '\0' && str[i] != ';' &&
	str[i] != '\n' && str[i] != '\t' &&
	str[i] != COM_CHAR && str[i] != ',')
	{
		if (str[i + 1] == ' ' || str[i + 1] == '\n' || str[i + 1] == '\0')
			return (asm_error(LBL_CHAR_ERROR));
		return (asm_error(LBLS_ERROR));
	}
	return (0);
}
