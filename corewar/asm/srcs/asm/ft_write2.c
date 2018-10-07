/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:50:02 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/26 13:57:52 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

static void	write_numbers(uint8_t *line, int len, int fd)
{
	int i;

	i = len;
	while (i--)
		write(fd, &line[i], 1);
}

static void	write_binary(uint8_t *line, int len, int fd)
{
	write(fd, line, len);
}

void		set_val(uint8_t *line, t_asm *data, int lfd, uint8_t *byte)
{
	line = (uint8_t*)(&data->header.magic);
	write_numbers(line, sizeof(unsigned int), lfd);
	line = (uint8_t*)data->header.prog_name;
	write_binary(line, PROG_NAME_LENGTH, lfd);
	write_binary(byte, 4, lfd);
	line = (uint8_t*)(&data->header.prog_size);
	write_numbers(line, sizeof(unsigned int), lfd);
	line = (uint8_t*)data->header.comment;
	write_binary(line, COMMENT_LENGTH, lfd);
	write_binary(byte, 4, lfd);
}
