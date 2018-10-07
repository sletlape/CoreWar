/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_realloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:26:00 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:26:01 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*asm_realloc(char *line, char *file, int i)
{
	int		len;
	char	*tmp;
	char	*sub;

	len = 0;
	tmp = NULL;
	sub = NULL;
	sub = ft_strsub(line, i, ft_strlen(line) - i);
	if (!(tmp = malloc(sizeof(char) * (ft_strlen(file) + ft_strlen(sub) + 2))))
		return (NULL);
	tmp = ft_strcpy(tmp, file);
	tmp = ft_strcat(tmp, sub);
	free(file);
	free(sub);
	file = NULL;
	sub = NULL;
	while (tmp[len])
		len++;
	tmp[len] = '\n';
	tmp[len + 1] = '\0';
	file = ft_strdup(tmp);
	free(tmp);
	return (file);
}
