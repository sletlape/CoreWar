/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getoptions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 09:54:56 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/19 12:03:30 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void			combine_error(char *buf, char *err1, char *err2)
{
	ft_strcpy(buf, err1);
	ft_strcat(buf, err2);
}

static void		set_options_val(char *op, char **av, int i, t_arena *arena)
{
	if (!ft_strcmp(op, "-dump"))
		arena->dump = ft_atoi(av[i + 1]);
	if (!ft_strcmp(op, "-n"))
		arena->number = ft_atoi(av[i + 1]);
}

static char		get_option_value(char *op, char **av, t_arena *arena, int i)
{
	char temp[MAX_ERROR];

	ft_bzero(temp, MAX_ERROR);
	if (!av[i + 1])
	{
		combine_error(temp, op, " : value expected after the option");
		free(op);
		exit_prog(temp, arena);
	}
	if (!ft_isnumbers(av[i + 1]))
	{
		free(op);
		combine_error(temp, op, " : number expected after the option");
		exit_prog(temp, arena);
	}
	if ((!ft_strcmp(op, "-dump") && (arena->dump > 0)) ||
			(!ft_strcmp(op, "-n") && (arena->number > 1)))
	{
		free(op);
		combine_error(temp, op, " : is already defined");
		exit_prog(temp, arena);
	}
	set_options_val(op, av, i, arena);
	return (TRUE);
}

static char		option_ok(char *op, char **av, t_arena *arena, int i)
{
	if (!ft_strcmp(op, "-dump") || !ft_strcmp(op, "-n"))
	{
		if (!get_option_value(op, av, arena, i))
			return (FALSE);
		return (TRUE);
	}
	else if (ft_strequ(op, "-trace") || ft_strequ(op, "-t"))
	{
		if (ft_strequ(op, "-trace"))
			arena->trace = TRUE;
		if (ft_strequ(op, "-t"))
			arena->visual = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

char			get_options(int ac, char **av, char *err, t_arena *arena)
{
	int		i;
	char	*trim;

	i = 0;
	ft_bzero(err, MAX_ERROR);
	init_arena(arena);
	ft_bzero(arena->arena, MEM_SIZE);
	while (++i < ac)
	{
		if (!(trim = ft_strtrim(av[i])))
			exit_prog("Invalid option detected", arena);
		if (trim[0] == '-')
		{
			if (!option_ok(trim, av, arena, i))
			{
				ft_strcpy(err, "Invalid option : ");
				ft_strcat(err, trim);
				free(trim);
				return (FALSE);
			}
		}
		free(trim);
	}
	return (TRUE);
}
