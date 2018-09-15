/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msefako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:58:39 by msefako           #+#    #+#             */
/*   Updated: 2018/09/01 14:58:49 by msefako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *begin_list)
{
	int		i;
	t_list	*test;

	test = begin_list;
	i = 0;
	while (test != NULL)
	{
		test = test->next;
		i++;
	}
	return (i);
}
