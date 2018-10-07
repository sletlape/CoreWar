/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_champ_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:26:28 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:26:30 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		display_champ_name(t_hdr *head)
{
	ft_printf("%-15s : %s\n", "Name of Champion", head->prog_name);
	ft_printf("%-15s : %s\n", "Comment", head->comment);
}
