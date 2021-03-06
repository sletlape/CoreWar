/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:28:44 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/03 15:48:06 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	int diff;

	diff = 'a' - 'A';
	if (c >= 'a' && c <= 'z')
		return (c - diff);
	return (c);
}
