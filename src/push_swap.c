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

char	*algo1(t_stack_a *st_a, t_stack_b *st_b)
{
	char	*process;

	process = NULL;

	if (st_a->data[0] > st_a->data[0 + 1])
	{
		ft_sa(st_a);
	}
	else if (st_a->data[0] > st_a->data[st_a->top])
	{
		ft_rra(st_a);
	}
	else if (st_a->data[0] < st_a->data[st_a->top])
	{
		ft_ra(st_a);
	}
	else if (st_a->data[0] < st_a->data[st_a->top] && st_a->data[0 + 1] > st_a->data[st_a->top])
	{
		ft_ra(st_a);
		ft_sa(st_a);
	}
	else if (ft_stack_checker() != 1)
	{
		ft_pb(st_a, st_b);
		algo1(st_a, st_b);
	}
	else
	{
		if (ft_checker(st_a, st_b) != 1 && st_b->top >-1)
		{
			ft_pb(st_a, st_b);
			algo1(st_a, st_b);
			ft_checker(st_a, st_b) == 1 ?  ft_putstr("step(s) done above && stop\n") : ft_putstr("step(s) done above && continue\n");
		}
		else if (ft_checker(st_a, st_b) == 1)
		{
			ft_putstr("step(s) done above && stop\n");
		}
	}
	return (process);
}

char	*my_ps_ai(t_stack_a *st_a, t_stack_b *st_b)
{
	char	*prc0;
	char	*prc1;

	algo1(st_a, st_b);
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
			my_ps_ai(&st_a, &st_b);
		}
	}
	free(st_a.data);
	free(st_b.data);
	return (0);
}
