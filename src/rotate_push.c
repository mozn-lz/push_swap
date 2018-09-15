/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msefako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:09:47 by msefako           #+#    #+#             */
/*   Updated: 2018/09/12 11:04:23 by msefako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fn_ra(t_stack_a *st_a)
{
	int	tmp;
	int	fst;
	int	i;

	tmp = 0;
	fst = st_a->data[0];
	i = 0;
	while (i <= st_a->top)
	{
		tmp = st_a->data[i + 1];
		st_a->data[i] = st_a->data[i + 1];
		i++;
		st_a->data[i] = tmp;
	}
	st_a->data[st_a->top] = fst;
}

void	fn_rb(t_stack_b *st_b)
{
	int	tmp;
	int	fst;
	int	i;

	tmp = 0;
	fst = st_b->data[0];
	i = 0;
	while (i <= st_b->top)
	{
		tmp = st_b->data[i + 1];
		st_b->data[i] = st_b->data[i + 1];
		i++;
		st_b->data[i] = tmp;
	}
	st_b->data[st_b->top] = fst;
}

void	fn_rr(t_stack_a *st_a, t_stack_b *st_b)
{
	fn_ra(st_a);
	fn_rb(st_b);
}

void	fn_pa(t_stack_a *st_a, t_stack_b *st_b)
{
	if (st_b->top > -1)
	{
		st_a->top++;
		st_a->data[st_a->top] = st_b->data[st_b->top];
		st_b->top--;
	}
}

void	fn_pb(t_stack_a *st_a, t_stack_b *st_b)
{
	if (st_a->top > -1)
	{
		st_b->top++;
		st_b->data[st_b->top] = st_a->data[st_a->top];
		st_a->top--;
	}
}
