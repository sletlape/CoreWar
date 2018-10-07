/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:23:42 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:23:43 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*cleaner;
	void	*ret;

	if ((ret = malloc(sizeof(char) * size)))
	{
		cleaner = (char*)ret;
		while (size)
		{
			cleaner[size - 1] = 0;
			size--;
		}
	}
	return (ret);
}
