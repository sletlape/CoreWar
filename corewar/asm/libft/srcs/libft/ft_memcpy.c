/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:23:46 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:23:48 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	t_uc	*from;
	t_uc	*to;

	from = (t_uc*)src;
	to = (t_uc*)dest;
	while (n--)
		*to++ = *from++;
	return (dest);
}
