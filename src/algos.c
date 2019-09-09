/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msefako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:43:59 by msefako           #+#    #+#             */
/*   Updated: 2019/09/09 22:44:04 by msefako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

	int cout = 0;	

int		ft_check_a(t_stack_a *st_a)
{
	int i;

	i = 0;
	if (st_a->top != -1)
	{
		i = st_a->top;
		while(i >= 0)
		{
			if (i - 1 == -1)
				break ;
			if (st_a->data[i] > st_a->data[i - 1])
			{
				return (0);
			}
			i--;
		}
	}
	return (1);
}

int		ft_check_b(t_stack_b *st_b)
{
	int i;

	i = 0;
	if (st_b->top != -1)
	{
		i = st_b->top;
		while(i >= 0)
		{
			if (i - 1 == -1)
				break ;
			if (st_b->data[i] > st_b->data[i - 1])
				return (0);
			i--;
		}
	}
	return (1);
}

int		ft_stack_checker(t_stack_a *st_a, t_stack_b *st_b)
{
	if ((ft_check_a(st_a) == 0) ||(ft_check_b(st_b) == 0))
		return (0);
	return (1);
}

void	algo2(t_stack_a *s_a, t_stack_b *s_b)
{
	if ((s_a->top > -1) && (ft_checker(s_a, s_b) == 0))
	{
		if (s_a->data[s_a->top - 1] > s_a->data[0] && s_a->data[s_a->top] < s_a->data[s_a->top - 1] && (s_a->top + s_b->top > 10))
		{
			ft_putnbr(++cout);
			ft_putstr("sa\n");
			fn_sa(s_a);
			ft_putnbr(++cout);
			ft_putstr("ra\n");
			fn_ra(s_a);
		}
		if (s_a->data[s_a->top - 1] < s_a->data[s_a->top])
		{
			ft_putnbr(++cout);
			ft_putstr("sa\n");
			fn_sa(s_a);
		}
		else if (s_a->data[0] < s_a->data[s_a->top])
		{
				ft_putnbr(++cout);
			ft_putstr("rra\n");
			fn_rra(s_a);
		}
		else if ((ft_check_a(s_a) == 0) && (s_a->top > -1))
		{
			ft_putnbr(++cout);
			ft_putstr("pb\n");
			fn_pb(s_a, s_b);
		}

		if (s_b->top > -1)
		{
			if (s_b->data[s_b->top - 1] < s_b->data[0] && s_b->data[s_b->top] > s_b->data[s_b->top - 1])
			{
				ft_putnbr(++cout);
				ft_putstr("sb\n");
				fn_sb(s_b);
				ft_putnbr(++cout);
				ft_putstr("rb\n");
				fn_rb(s_b);
			}
			if (s_b->data[s_b->top - 1] > s_b->data[s_b->top] && s_b->data[s_a->top] > 0)
			{
				ft_putnbr(s_b->data[s_a->top]);
				ft_putnbr(++cout);
				ft_putstr("sb\n");
				fn_sb(s_b);
			}
			else if (s_b->data[0] > s_b->data[s_b->top])
			{
				ft_putnbr(++cout);
				ft_putstr("rrb\n");
				fn_rrb(s_b);
			}
			else if (ft_check_a(s_a) == 1)
			{
				ft_putnbr(++cout);
				ft_putstr("pa\n");
				fn_pa(s_a, s_b);
			}
		}
	}
}
