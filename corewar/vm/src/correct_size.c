/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 09:41:11 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/23 09:42:11 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	set_correct_size(unsigned char *size, int len)
{
	if (size[0] == IND_SIZE)
		size[0] = REG_SIZE;
	else if (size[0] == REG_SIZE)
		size[0] = IND_SIZE;
	if (size[1] == REG_SIZE)
		size[1] = IND_SIZE;
	else if (size[1] == IND_SIZE)
		size[1] = REG_SIZE;
	if (len < 3)
		return ;
	if (size[2] == REG_SIZE)
		size[2] = IND_SIZE;
	else if (size[2] == IND_SIZE)
		size[2] = REG_SIZE;
}
