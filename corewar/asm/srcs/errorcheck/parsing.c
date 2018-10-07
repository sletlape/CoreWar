/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:27:12 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 09:40:00 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			parsing(char *champion, t_hdr *head, int check)
{
	int			fd;
	char		*file;
	t_label		*label;

	label = NULL;
	file = NULL;
	check_champ_name(champion);
	if ((fd = open(champion, O_RDONLY, 0555)) == -1)
		return (-1);
	name_comment_handler(fd, head);
	if (check == 1)
		display_champ_name(head);
	label = parse_line(fd, &file);
	check_double_label(label);
	if (check_label_exist(label, file) == 0)
		return (asm_error(ARG_ERROR));
	if (file && file[0])
		free(file);
	if (label)
		free_label(label);
	return (0);
}
