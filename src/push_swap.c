/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msefako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 07:15:48 by msefako           #+#    #+#             */
/*   Updated: 2018/09/19 07:15:54 by msefako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_checker(t_stack_a *st_a, t_stack_b *st_b)
{
	int i;

	i = st_a->top;
	if (st_b->top < 0)
	{
		while (i > -1)
		{
			if (st_a->data[i] > st_a->data[i - 1])
				break ;
			i--;
		}
		if (i <= 0)
		{
			return (1);
		}
	}
	return (0);
}

void	fn_print_stack(t_stack_a *st_a, t_stack_b *st_b)
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

char	*my_ps_ai(t_stack_a *st_a, t_stack_b *st_b)
{
	char	*cmds;
	int		i;

	i = -1;
	cmds = NULL;
	cmds = (char*)malloc(sizeof(char*) * 100);
	while (ft_checker(st_a, st_b) == 0) 
		algo2(st_a, st_b, cmds, i);
	return(cmds);
}

void	init(t_stack_a *st_a, t_stack_b *st_b, char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	st_a->top = i - 1;
	st_b->top = -1;
	st_a->data = (int*)malloc(sizeof(int) * i);
	st_b->data = (int*)malloc(sizeof(int) * i);
}

int		main(int ac, char **av)
{
	char		**tab;
	t_stack_a	st_a;
	t_stack_b	st_b;

	tab = NULL;
	if (ac >= 2)
	{
		tab = err_ctrl(ac, av);
		init(&st_a, &st_b, tab);
		if (number_error(tab, &st_a) != 0)
		{
			fn_print_stack(&st_a, &st_b);
			if (ft_checker(&st_a, &st_b) == 0)
				my_ps_ai(&st_a, &st_b);
	fn_print_stack(&st_a, &st_b);
	// (!tab) ? 1: free(tab);
	free(st_a.data);
	free(st_b.data);
		}
	}
	return (0);
}
