/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:53:25 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/19 11:56:28 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static void		get_operand(char op)
{
	char opchar;

	opchar = 'U';
	ft_putchar('\n');
	if (op == ADD)
		opchar = '+';
	else if (op == SUB)
		opchar = '-';
	else if (op == AND)
		opchar = '&';
	else if (op == OR)
		opchar = '|';
	else if (op == XOR)
		opchar = '^';
	ft_putchar(' ');
	ft_putchar(opchar);
	ft_putchar(' ');
}

void			show_reg_operation(int *val, int size, int op)
{
	int i;
	int sum;

	i = -1;
	sum = 0;
	while (++i < size)
	{
		if (i != 0)
			get_operand(op);
		ft_putnbr(val[i]);
		if (op == ADD)
			sum += val[i];
		else if (op == SUB)
			sum -= val[i];
		else if (op == AND)
			sum &= val[i];
		else if (op == OR)
			sum |= val[i];
		else if (op == XOR)
			sum ^= val[i];
	}
	ft_putstr(" = ");
	ft_putnbr(sum);
	ft_putline();
	getchar();
}

void			show_one_champ(t_champ *champ)
{
	int	i;

	i = -1;
	ft_putstr("\nID : ");
	ft_putnbr(champ->id);
	ft_putstr("\nChamp Name : ");
	ft_putendl(champ->name);
	ft_putstr("Champ Comment : ");
	ft_putendl(champ->comment);
	ft_putstr("Live calls : ");
	ft_putnbr(champ->alive);
	ft_putstr("\nRegs : ");
	while (++i < REG_NUMBER)
	{
		ft_putnbr(champ->reg[i]);
		ft_putchar(' ');
	}
	ft_putstr("\nCarry : ");
	ft_putnbr(champ->carry);
	ft_putstr("\nPC : ");
	ft_putnbr(champ->pc);
	ft_putstr("\nwait : ");
	ft_putnbr(champ->wait);
	ft_putstr("\n\n");
}

void			show_all_champs(t_champ **head)
{
	t_champ *temp;

	temp = (*head);
	while (temp)
	{
		show_one_champ(temp);
		temp = temp->next;
	}
}
