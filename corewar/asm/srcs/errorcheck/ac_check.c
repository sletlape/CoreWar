/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:25:48 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:25:50 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ac_check(int ac)
{
	if (ac == 2)
		asm_error(CHAMPION_ERROR);
	return (1);
}
