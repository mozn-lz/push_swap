/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozn <mozn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 19:30:46 by msefako           #+#    #+#             */
/*   Updated: 2019/08/29 22:30:45 by mozn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_err(char *err)
{
	fprintf(stderr, "Error: %s", err);
	fflush(stderr);
}

int		find_dup(t_stack_a *st_a)
{
	int	i;
	int	j;
	int	indi;

	i = -1;
	while (++i <= st_a->top)
	{
		indi = -1;
		j = -1;
		while (++j <= st_a->top)
		{
			if (st_a->data[i] == st_a->data[j])
			{
				indi++;
				if (indi == 1)
				{
					print_err("Duplicate number\n");
					return (0);
				}
			}
		}
	}
	return (1);
}

int		store(char **av, t_stack_a *st_a)
{
	int			i;

	i = st_a->top + 1;
	while (--i >= 0)
		st_a->data[i] = ft_atoi(av[st_a->top - i]);
	if (find_dup(st_a) == 0)
		return (0);
	return (1);
}

int		number_error(char **av, t_stack_a *st_a)
{
	int		i;
	int		j;

	i = -1;
		// ft_putstr("\n");
	while (++i < st_a->top + 1)
	{
		j = -1;
		while (av[i][++j] != '\0')
			if (ft_isdigit(av[i][j]) == 0)
			{
				print_err("Argument is not a number\n");
				return (0);
			}
		if (ft_atoli(av[i]) < 0 || ft_atoli(av[i]) > 2147483647)
		{
			print_err("Number is out of range\n");
			return (0);
		}
	}
	if (store(av, st_a) == 0)
		return (0);
	return (1);
}

char	**err_ctrl(int ac, char **av)
{
	char	**tab;
	int		i;

	i = 0;
	tab = NULL;
	if (ac == 2)
	{
		if (ft_strchr(av[1], '\t') != NULL)
			tab = ft_strsplit(av[1], '\t');
		else if (ft_strchr(av[1], ' ') != NULL)
			tab = ft_strsplit(av[1], ' ');
		else
		{
			tab = av + 1;
			while (++i < ac)
				tab[i - 1] = av[i];
		}
	}
	else if (ac > 2)
	{
		tab = av + 1;
		while (++i < ac)
			tab[i - 1] = av[i];
	}
	return (tab);
}
