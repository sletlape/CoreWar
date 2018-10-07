/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:24:44 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:24:45 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	cur;
	char	*tmp;

	cur = 0;
	tmp = dest + ft_strlen(dest);
	while (*src && cur < n)
	{
		tmp[cur] = *src;
		++cur;
		++src;
	}
	tmp[cur] = '\0';
	return (dest);
}
