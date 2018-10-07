/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:24:54 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:24:55 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;
	size_t	index;

	if ((ret = (char*)malloc(sizeof(char) * (size + 1))))
	{
		index = 0;
		while (index < (size + 1))
			ret[index++] = '\0';
	}
	return (ret);
}
