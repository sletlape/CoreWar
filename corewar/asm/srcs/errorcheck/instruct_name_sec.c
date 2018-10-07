/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_name_sec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:26:52 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:26:59 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	instruct_name_sec(char *line)
{
	if (ft_strncmp("ldi", line, 3) == 0)
		return (LDI);
	if (ft_strncmp("ld", line, 2) == 0)
		return (LD);
	if (ft_strncmp("fork", line, 4) == 0)
		return (FORK);
	if (ft_strncmp("st", line, 2) == 0)
		return (ST);
	if (ft_strncmp("lldi", line, 4) == 0)
		return (LLDI);
	if (ft_strncmp("lld", line, 3) == 0)
		return (LLD);
	if (ft_strncmp("lfork", line, 5) == 0)
		return (LFORK);
	if (ft_strncmp("aff", line, 3) == 0)
		return (AFF);
	return (0);
}
