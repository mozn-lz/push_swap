/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msefako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:09:30 by msefako           #+#    #+#             */
/*   Updated: 2018/09/10 17:09:32 by msefako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fn_sa(t_stack_a *st_a)
{
	int	tmp;

	tmp = 0;
	if (st_a->top > 0)
	{
		tmp = st_a->data[st_a->top - 1];
		st_a->data[st_a->top - 1] = st_a->data[st_a->top];
		st_a->data[st_a->top] = tmp;
	}
}

void	fn_sb(t_stack_b *st_b)
{
	int	tmp;

	tmp = 0;
	if (st_b->top > 0)
	{
		tmp = st_b->data[st_b->top - 1];
		st_b->data[st_b->top - 1] = st_b->data[st_b->top];
		st_b->data[st_b->top] = tmp;
	}
}

void	fn_ss(t_stack_a *st_a, t_stack_b *st_b)
{
	fn_sa(st_a);
	fn_sb(st_b);
}
