/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 14:51:27 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/09 10:44:13 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_digits(int num)
{
	int dig;

	if (num < 0)
	{
		if (num <= -2147483648)
			num = 2147483640;
		else
			num = -(num);
	}
	dig = 0;
	while (num > 0)
	{
		num /= 10;
		dig++;
	}
	return (dig);
}
