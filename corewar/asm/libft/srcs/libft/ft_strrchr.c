/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:24:56 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:24:57 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	size_t	index;

	index = ft_strlen(s);
	if (index == 0 && (char)c == 0)
		return (s);
	index++;
	while (index)
	{
		--index;
		if (s[index] == (char)c)
			return (s + index);
	}
	return (0);
}
