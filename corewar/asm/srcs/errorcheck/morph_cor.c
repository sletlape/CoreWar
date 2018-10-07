/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morph_cor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:27:07 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:27:08 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*morph_cor(char *champ)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = malloc(sizeof(char*) * (ft_strlen(champ) + 3))))
		return (NULL);
	while (champ[i])
	{
		str[i] = champ[i];
		i++;
	}
	str[i - 1] = 'c';
	str[i] = 'o';
	str[++i] = 'r';
	str[++i] = '\0';
	return (str);
}
