/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:23:15 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:23:16 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *nbr)
{
	unsigned int	value;
	int				sign;

	while (*nbr == ' ' || *nbr == '\t' || *nbr == '\n' || *nbr == '\f' || \
			*nbr == '\r' || *nbr == '\v')
		nbr++;
	sign = 1;
	if (*nbr == '-' || *nbr == '+')
	{
		sign = *nbr == '-' ? -1 : 1;
		nbr++;
	}
	value = 0;
	while (*nbr >= '0' && *nbr <= '9')
	{
		value *= 10;
		value += *nbr++ - '0';
	}
	return (value * sign);
}
