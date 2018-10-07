/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:26:35 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 10:26:06 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_hdr		*header_init(void)
{
	t_hdr	*new;

	if (!(new = (t_hdr*)malloc(sizeof(t_hdr))))
		return (NULL);
	if (new != NULL)
	{
		new->magic = COREWAR_EXEC_MAGIC;
		new->prog_size = 0;
		ft_bzero(new->prog_name, PROG_NAME_LENGTH);
		ft_bzero(new->comment, COM_LENGTH);
	}
	return (new);
}
