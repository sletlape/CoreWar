/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:24:27 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:24:28 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while ((t_uc) * s1 == (t_uc) * s2 && *s1 && *s2)
	{
		++s1;
		++s2;
	}
	return ((t_uc) * s1 - (t_uc) * s2);
}
