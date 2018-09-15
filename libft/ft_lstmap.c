/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msefako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:57:50 by msefako           #+#    #+#             */
/*   Updated: 2018/09/01 14:57:59 by msefako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin_list;
	t_list	*temp;
	t_list	*temp2;

	temp = f(lst);
	begin_list = ft_lstnew(temp->content, temp->content_size);
	if (begin_list == 0)
		return (0);
	temp2 = begin_list;
	if (lst)
	{
		lst = lst->next;
		while (lst)
		{
			temp = f(lst);
			temp2->next = ft_lstnew(temp->content, temp->content_size);
			if (temp2->next == 0)
				return (0);
			temp2 = temp2->next;
			lst = lst->next;
		}
	}
	return (begin_list);
}
