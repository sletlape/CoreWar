/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:23:51 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:23:52 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	t_uc	*from;
	t_uc	*to;

	from = (t_uc*)src;
	to = (t_uc*)dest;
	if (src + n >= dest && src < dest)
		while (n--)
			to[n] = from[n];
	else
		while (n--)
			*to++ = *from++;
	return (dest);
}
