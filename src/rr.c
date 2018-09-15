/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msefako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:09:39 by msefako           #+#    #+#             */
/*   Updated: 2018/09/10 17:09:42 by msefako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fn_rra(t_stack_a *st_a)
{
	int	tmp;
	int	fst;
	int	i;

	tmp = 0;
	fst = st_a->data[st_a->top];
	i = st_a->top;
	while (i >= 0)
	{
		tmp = st_a->data[i - 1];
		st_a->data[i] = st_a->data[i - 1];
		i--;
		st_a->data[i] = tmp;
	}
	st_a->data[0] = fst;
}

void	fn_rrb(t_stack_b *st_b)
{
	int	tmp;
	int	fst;
	int	i;

	tmp = 0;
	fst = st_b->data[st_b->top];
	i = st_b->top;
	while (i >= 0)
	{
		tmp = st_b->data[i - 1];
		st_b->data[i] = st_b->data[i - 1];
		i--;
		st_b->data[i] = tmp;
	}
	st_b->data[0] = fst;
}

void	fn_rrr(t_stack_a *st_a, t_stack_b *st_b)
{
	fn_rra(st_a);
	fn_rrb(st_b);
}
