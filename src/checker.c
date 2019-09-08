/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozn <mozn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 19:30:46 by msefako           #+#    #+#             */
/*   Updated: 2019/09/02 15:20:54 by mozn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_put_char_arr(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
	{
		ft_putstr(tab[i]);
		ft_putstr("\n");
	}
}

void ft_put_int_arr(int *tab)
{
	int i;

	i = -1;
	while (tab[++i])
	{
		ft_putnbr(tab[i]);
		ft_putstr("\n");
	}
}

int ft_checker(t_stack_a *st_a, t_stack_b *st_b)
{
	int i;

	i = st_a->top;
	if (st_b->top < 0)
	{
		while (i > -1)
		{
			if (i - 1 == -1)
				break;
			if (st_a->data[i] > st_a->data[i - 1])
				break;
			i--;
		}
		if (i <= 0)
		{
			return (1);
		}
	}
	return (0);
}

void fn_print_stack(t_stack_a *st_a, t_stack_b *st_b)
{
	int i;

	if (st_a->top >= st_b->top)
		i = st_a->top + 1;
	else
		i = st_b->top + 1;
	if (st_a->top > -1 || st_b->top > -1)
	{
		(st_a->data) ? ft_putstr("stack A\t\t") : 1;
		(st_b->data) ? ft_putstr("stack B") : 1;
		ft_putstr("\n");
		while (--i >= 0 || i >= st_a->top)
		{
			ft_putstr("   ");
			(i <= st_a->top) ? ft_putnbr(st_a->data[i]) : 1;
			ft_putstr("\t\t\t");
			(i <= st_b->top) ? ft_putnbr(st_b->data[i]) : 1;
			ft_putstr("\n");
		}
	}
	ft_putstr("\n");
}

void ft_intercept(t_stack_a *st_a, t_stack_b *st_b, char *cmd)
{
	if (ft_strcmp(cmd, "rra") == 0)
		fn_rra(st_a);
	else if (ft_strcmp(cmd, "rrb") == 0)
		fn_rrb(st_b);
	else if (ft_strcmp(cmd, "rrr") == 0)
		fn_rrr(st_a, st_b);
	else if (ft_strcmp(cmd, "rr") == 0)
		fn_rr(st_a, st_b);
	else if (ft_strcmp(cmd, "ra") == 0)
		fn_ra(st_a);
	else if (ft_strcmp(cmd, "rb") == 0)
		fn_rb(st_b);
	else if (ft_strcmp(cmd, "pa") == 0)
		fn_pa(st_a, st_b);
	else if (ft_strcmp(cmd, "pb") == 0)
		fn_pb(st_a, st_b);
	else if (ft_strcmp(cmd, "sa") == 0)
		fn_sa(st_a);
	else if (ft_strcmp(cmd, "sb") == 0)
		fn_sb(st_b);
	else if (ft_strcmp(cmd, "ss") == 0)
		fn_ss(st_a, st_b);
	else
		print_err("Invalid Instruction\n");
}

void init(t_stack_a *st_a, t_stack_b *st_b, char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	st_a->top = i - 1;
	st_b->top = -1;
	st_a->data = (int *)malloc(sizeof(int) * i);
	st_b->data = (int *)malloc(sizeof(int) * i);
}

int main(int ac, char **av)
{
	char **tab;
	char *cmd;
	t_stack_a st_a;
	t_stack_b st_b;

	tab = NULL;
	if (ac >= 2)
	{
		tab = err_ctrl(ac, av);
		init(&st_a, &st_b, tab);
		if (number_error(tab, &st_a) != 0)
		{
			cmd = NULL;
			while (get_next_line(0, &cmd) > 0)		//	get/read commads
			{
				ft_intercept(&st_a, &st_b, cmd);		//	interprete commands
				// fn_print_stack(&st_a, &st_b);
			}
			(ft_checker(&st_a, &st_b) == 1) ? ft_putstr("OK\n") : ft_putstr("KO\n");
		}
		(st_a.data) ? free(st_a.data) : 1;
		(st_b.data) ? free(st_b.data) : 1;
	}
	return (0);
}
