/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:52:58 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/19 11:53:02 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	access_data(unsigned char *arena, int size, int pos, unsigned char *buf)
{
	int i;

	i = 0;
	pos = (pos % MEM_SIZE);
	pos = (pos < 0) ? MEM_SIZE - pos : pos;
	while (i < size)
	{
		if (pos > (MEM_SIZE - 1))
			pos = 0;
		buf[i++] = arena[pos++];
	}
}

void	write_toarena(t_arena *arena, unsigned char *bytes, int pos, int size)
{
	int	x;

	x = 0;
	pos = (pos % MEM_SIZE);
	pos = (pos < 0) ? MEM_SIZE - pos : pos;
	while (x < size)
	{
		if (pos > (MEM_SIZE - 1))
			pos = 0;
		arena->arena[pos++] = bytes[x++];
	}
}
