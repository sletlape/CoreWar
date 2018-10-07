/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_ok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:26:33 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/18 14:19:48 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_fileok(char *av)
{
	t_hdr		*head;
	int			check;

	check = 0;
	head = NULL;
	init_global();
	if ((head = header_init()) == NULL)
		return (asm_error(MALLOC_ERROR));
	if (parsing(av, head, check) == -1)
		return (asm_error(CHAMPION_ERROR));
	free(head);
	head = NULL;
	if (g_error == 0)
		ft_printf_fd(2, "The file %s is OK!\n", av);
	init_global();
	return (1);
}
