/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 10:26:34 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/26 13:59:11 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

static void	write_numbers(uint8_t *line, int len, int fd)
{
	int	i;

	i = len;
	while (i--)
		write(fd, &line[i], 1);
}

static void	write_name_comment(t_header header)
{
	ft_putstr("\t");
	ft_putendl(header.prog_name);
	ft_putstr("\t");
	ft_putendl(header.comment);
}

void		write_conv_data(t_conv *instruct, int fd)
{
	int			i;
	uint8_t		*temp;

	i = -1;
	write(fd, &instruct->opcode, 1);
	if (instruct->hasencoding)
		write(fd, &instruct->encoding, 1);
	while (++i < instruct->n_params)
	{
		temp = (uint8_t*)&instruct->param[i];
		write_numbers(temp, instruct->b_param[i], fd);
	}
	temp = 0;
}

void		write_to_cor(t_asm *data)
{
	int		lfd;
	uint8_t	*line;
	uint8_t	byte[5];
	t_conv	*iter;
	char	*fncor;

	fncor = get_fn_cor(data->fn);
	ft_bzero(byte, 5);
	if ((lfd = open(fncor, O_CREAT | O_WRONLY, S_IWUSR | S_IRUSR)) == -1)
	{
		ft_putendl("File not created");
		return ;
	}
	line = NULL;
	set_val(line, data, lfd, byte);
	iter = data->line;
	while (iter != NULL)
	{
		if (ft_strlen(iter->line) > 0)
			write_conv_data(iter, lfd);
		iter = iter->next;
	}
	write_name_comment(data->header);
	free(fncor);
	close(lfd);
}
