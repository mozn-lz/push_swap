/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msefako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 19:30:46 by msefako           #+#    #+#             */
/*   Updated: 2018/09/14 15:41:02 by msefako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_err(char *err)
{
	fprintf(stderr, "Error: %s\n", err);
	fflush(stderr);
}

void	ft_intercept(t_stack_a *st_a, t_stack_b *st_b, char *cmd)
{
	// fn_print_stack(st_a, st_b);
	if (ft_strstr(cmd, "rra") != 0)
		fn_rra(st_a);
	else if (ft_strstr(cmd, "rrb") != 0)
		fn_rrb(st_b);
	else if (ft_strstr(cmd, "rrr") != 0)
		fn_rrr(st_a, st_b);
	else if (ft_strstr(cmd, "rr") != 0)
		fn_rr(st_a, st_b);
	else if (ft_strstr(cmd, "ra") != 0)
		fn_ra(st_a);
	else if (ft_strstr(cmd, "rb") != 0)
		fn_rb(st_b);
	else if (ft_strstr(cmd, "pa") != 0)
		fn_pa(st_a, st_b);
	else if (ft_strstr(cmd, "pb") != 0)
		fn_pb(st_a, st_b);
	else if (ft_strstr(cmd, "sa") != 0)
		fn_sa(st_a);
	else if (ft_strstr(cmd, "sb") != 0)
		fn_sb(st_b);
	else if (ft_strstr(cmd, "ss") != 0)
		fn_ss(st_a, st_b);
	else
		print_err("Invalid Instruction");
}

void	get_cmd(t_stack_a *st_a, t_stack_b *st_b)
{
		ft_putstr("get_cmd(t_stack_a *st_a, t_stack_b *st_b)\n");
	char	**cmd;

	cmd = NULL;
	while (get_next_line(1, cmd))
	{
		ft_intercept(st_a, st_b, *cmd);
	}
	free(cmd);
}

void	init(t_stack_a *st_a, t_stack_b *st_b, char **tab)
{
		ft_putstr("init(t_stack_a *st_a, t_stack_b *st_b, char **tab)\n");
	int i;

	i = 0;
	i = (sizeof(tab) / sizeof(tab[0]));
	(ft_isdigit(tab[0][0] == 0)) ? i-- : 1;
	st_a->top = i - 1;
	st_b->top = i - 1;
	st_a->data = (int*)malloc(sizeof(int) * i);
	st_b->data = (int*)malloc(sizeof(int) * i);
}

void	store(int ac, char **av)
{
		ft_putstr("\n\n\n\nstore(int ac, char **av)\n");
	char		**tab;
	int			i;
	int			j;
	t_stack_a	st_a;
	t_stack_b	st_b;

	tab = NULL;
	i = -1;
	if (ac == 2)
	{
		if (ft_strrchr(av[1], '\t'))
			tab = ft_strsplit(av[1], '\t');
		else if (ft_strrchr(av[1], ' '))
			tab = ft_strsplit(av[1], ' ');
	}
	else if (ac > 2)
		tab = av;
	init(&st_a, &st_b, tab);
	j = -1;
	while (++i < st_a.top)
		if (ft_isdigit(av[i][0] != 0))
			st_a.data[++j] = ft_atoi(av[i]);
	get_cmd(&st_a, &st_b);
	free(st_a.data);
	free(st_b.data);
}

int		number_error(char	**av, int ac)
{
		ft_putstr("\t\tnumber_error(char **av, int ac)\n");
	int		i;
	int		j;

	i = 0;
				printf("ac %d\n", ac);
	while (++i < ac)
	{
		j = -1;
				printf("av[i]\t %s\n", av[i]);
		while (av[i][++j] != '\0')
				printf("av[i] %s\n", av[i]);
			if (ft_isdigit(av[i][j]) == 0)
			{
				printf("tab>i %s\n", av[i]);
				print_err("Invalid Argument\n");
				return (0);
			}
		if ((ft_atoli(av[i]) < -2147483648 && ft_atoli(av[i]) > 2147483647) && (ft_isdigit(av[i][0]) != 0))
		{
			print_err("Number is out of range\n");
			return (0);
		}
	}
	store(ac, av);
	return (1);
}

int		main(int ac, char **av)
{
	char	**tab;
	int		sz;

	tab = NULL;
	if (ac >= 2)
	{
		if (ac == 2)
		{
				printf("____%d____\n", ac);
			if (ft_strrchr(*av, '\t'))
				tab = ft_strsplit(*av, '\t');
			else if (ft_strrchr(*av, ' '))
				tab = ft_strsplit(*av, ' ');
			sz = (sizeof(tab) / sizeof(tab[0]));
				printf("__SZ__%lu____%lu\n", sizeof(tab) , sizeof(tab[0]));
			number_error(tab, sz);
		}
		else if (ac > 2)
		{
			tab = av;
			number_error(tab, ac - 1);
		}
	}
	return (0);
}
