/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:24:48 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:24:49 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*tmp;

	tmp = dest;
	while (n && *src)
	{
		*dest = *src;
		++dest;
		++src;
		--n;
	}
	while (n)
	{
		*dest = '\0';
		++dest;
		--n;
	}
	return (tmp);
}
