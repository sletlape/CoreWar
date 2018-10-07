/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:31:02 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/19 11:32:43 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

static int	get_unique_id(t_champ **head)
{
	int		i;
	t_champ	*temp;
	char	okay;
	char	found;

	i = 0;
	okay = FALSE;
	if (!(temp = (*head)))
		return (-1);
	while (!okay)
	{
		temp = (*head);
		found = FALSE;
		while (temp && !found)
		{
			if ((found = temp->id == i))
				i = temp->id + 1;
			temp = temp->next;
		}
		okay = (!found);
	}
	return (i);
}

void		ft_fork(int pc, t_arena *arena, t_champ *champ)
{
	int				value[3];
	t_champ			*dup;

	if (inititate_wait(champ, arena, 799, "FORK"))
		return ;
	champ->run = NO;
	pc++;
	value[0] = get_one_value(IND_SIZE, pc, arena->arena, champ);
	if (!(dup = (t_champ *)ft_memdup((const unsigned char*)champ,
					sizeof(t_champ))))
		exit_prog("malloc error, cant fork process", arena);
	dup->next = NULL;
	dup->prev = NULL;
	dup->id = get_unique_id(&(arena->champs));
	dup->pc = (dup->pc + (value[0] % IDX_MOD)) % MEM_SIZE;
	add_champ(&(arena->champs), dup);
	champ->pc = (champ->pc + IND_SIZE + 1) % MEM_SIZE;
	show_trace("\nFORK instruction played by : ", arena,
			champ, SHOW_ALL_CHAMPS);
}
