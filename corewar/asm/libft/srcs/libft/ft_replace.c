/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:52:36 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:54:04 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_replace(char **str, char a, char b)
{
	int		index;

	index = 0;
	while ((*str)[index])
	{
		if ((*str)[index] == a)
			(*str)[index] = b;
		index++;
	}
}
