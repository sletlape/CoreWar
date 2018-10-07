/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_champ_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:26:08 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:26:09 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_champ_name(char *champ)
{
	int i;

	i = 0;
	while (champ[i])
		i++;
	if (i >= 3 && champ[i - 1] == 's' && champ[i - 2] == '.')
		return (1);
	else
		return (asm_error(FILE_ERROR));
}
