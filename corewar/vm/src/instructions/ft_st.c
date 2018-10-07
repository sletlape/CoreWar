/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:42:11 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/19 11:43:04 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

void	ft_st(int pc, t_arena *arena, t_champ *champ)
{
	unsigned char	*val;
	unsigned char	size[3];
	int				value[3];
	int				bytes;
	int				start;

	if (inititate_wait(champ, arena, 4, "ST"))
		return ;
	champ->run = NO;
	start = pc++;
	ft_bzero(size, 3);
	decode(arena->arena[pc], size);
	set_correct_size(size, 2);
	pc++;
	value[0] = get_one_value(size[0], pc, arena->arena, champ);
	pc += size[0];
	value[1] = (get_one_value(size[1], pc, arena->arena, champ));
	bytes = 2 + (size[0] + size[1]);
	champ->pc = (champ->pc + bytes) % MEM_SIZE;
	val = (unsigned char*)&value[0];
	convert_tobigendian(val);
	start = (start + (value[1] % IDX_MOD)) % MEM_SIZE;
	write_toarena(arena, val, start, REG_SIZE);
	show_trace("\nST played by : ", arena, champ, SHOW_BOTH);
}
