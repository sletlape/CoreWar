/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:44:09 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/27 18:00:08 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = (char)c;
	while ((s[i] != '\0') && (s[i] != ch))
		i++;
	if (s[i] == ch)
		return (char *)(s + i);
	return (NULL);
}
