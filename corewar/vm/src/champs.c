/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 11:40:13 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/23 09:58:33 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

int				bytes_tonum(unsigned char *bytes, int size)
{
	int		num;
	char	temp[4];

	num = 0;
	ft_bzero(temp, 4);
	if (size == T_REG)
		return ((int)bytes[0]);
	else if (size == T_DIR)
	{
		temp[3] = (bytes[0] > 240) ? 0xff : 0x00;
		temp[2] = (bytes[0] > 240) ? 0xff : 0x00;
		temp[1] = bytes[0];
		temp[0] = bytes[1];
		num = (*((int *)temp));
		return (num);
	}
	temp[3] = bytes[0];
	temp[2] = (size > 1) ? bytes[1] : 0;
	temp[1] = (size > 2) ? bytes[2] : 0;
	temp[0] = (size > 3) ? bytes[3] : 0;
	num = (*((int *)temp));
	return (num);
}

static void		set_champ(t_champ *champ, int ind, t_arena *arena)
{
	champ->reg[0] = arena->number;
	champ->playerno = arena->number++;
	champ->alive = 0;
	champ->freed = 0;
	champ->wait = 0;
	champ->index = 0;
	champ->next = NULL;
	champ->prev = NULL;
	champ->run = NO;
	champ->id = ind;
	champ->carry = 0;
}

static char		init_champ_header(unsigned char *buf, t_champ *champ,
		t_arena *arena, int ind)
{
	int				i;
	char			t_num[4];
	char			temp[MAX_ERROR];

	ft_bzero(temp, MAX_ERROR);
	if (buf[0] != 0x00 && buf[1] != 0xAE && buf[2] != 0x38 && buf[3] != 0x3f)
		exit_prog("Invalid champ detected", arena);
	i = 4;
	ft_memcpy((void*)champ->name, (const void*)(buf + i), PROG_NAME_LENGTH);
	i += PROG_NAME_LENGTH + 4;
	ft_memcpy((void*)t_num, (const char *)(buf + i), 4);
	champ->player_size = bytes_tonum((unsigned char*)t_num, T_IND);
	if (champ->player_size > CHAMP_MAX_SIZE)
	{
		combine_error(temp, champ->name, " is over max size");
		exit_prog(temp, arena);
	}
	i += 4;
	ft_memcpy((void*)champ->comment, (const char *)(buf + i), COMMENT_LENGTH);
	set_champ(champ, ind, arena);
	i = 0;
	while (++i < REG_NUMBER)
		champ->reg[i] = 0;
	ft_memset((void*)champ->prog, 0, CHAMP_MAX_SIZE);
	return (TRUE);
}

static void		read_header(t_arena *arena, int i, char *buff, t_champ *champ)
{
	int r;

	r = 0;
	if ((r = read(arena->fd[i], buff, HEADER_BYTES)) == -1)
	{
		close(arena->fd[i]);
		exit_prog("Error reading champ (Reading from file)", arena);
	}
	if (!init_champ_header((unsigned char*)buff, champ, arena, i) && r > 0)
	{
		close(arena->fd[i]);
		exit_prog("Error reading champ (Incorrect data)", arena);
	}
}

void			read_champs(t_arena *arena)
{
	int		i;
	t_champ	*champ;
	int		r;
	char	buff[HEADER_BYTES];

	i = -1;
	while (++i < arena->players)
	{
		if (!(champ = (t_champ*)malloc(sizeof(t_champ))))
			exit_prog("malloc error", arena);
		read_header(arena, i, buff, champ);
		if ((r = read(arena->fd[i], (char*)champ->prog,
			(int)champ->player_size)) != (int)champ->player_size)
		{
			close(arena->fd[i]);
			exit_prog("Player size does not match", arena);
		}
		add_champ(&(arena->champs), champ);
		close(arena->fd[i]);
	}
}
