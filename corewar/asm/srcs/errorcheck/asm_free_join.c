/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_free_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:25:55 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:25:57 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*asm_free_join(char *line, char *file)
{
	int		i;
	int		len;
	char	*sub;

	i = 0;
	sub = NULL;
	if (line[i])
	{
		if (!(len = 0) && !file)
		{
			sub = ft_strsub(line, i, ft_strlen(line) - i);
			if (!(file = malloc(sizeof(char) * (ft_strlen(sub) + 2))))
				return (NULL);
			file = ft_strcpy(file, sub);
			while (file[len])
				len++;
			file[len] = '\n';
			file[len + 1] = '\0';
			free(sub);
			sub = NULL;
		}
		else
			file = asm_realloc(line, file, i);
	}
	return (file);
}
