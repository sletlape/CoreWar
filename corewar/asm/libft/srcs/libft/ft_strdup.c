/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:24:36 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:24:37 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*out;
	size_t	cur;

	if ((out = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
	{
		cur = 0;
		while (s[cur])
		{
			out[cur] = s[cur];
			++cur;
		}
		out[cur] = '\0';
	}
	return (out);
}
