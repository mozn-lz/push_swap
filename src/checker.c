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
	char	**cmd;

		ft_putstr("\t\tGET	CMD\n$> ");
	cmd = NULL;
	while (get_next_line(1, cmd))
	{
		ft_putstr("enter comand\n$>");
		fprintf(stderr, "Err %s\n", *cmd);
		ft_putstr(*cmd);
		ft_putstr("\n");
		ft_intercept(st_a, st_b, *cmd);
	}
	free(cmd);
}

void	init(t_stack_a *st_a, t_stack_b *st_b, char **tab)
{
	int i;

		ft_putstr("init(t_stack_a *st_a, t_stack_b *st_b, char **tab)\n");
	i = 0;
	while (tab[i])
		i++;
	st_a->top = i - 1;
	st_b->top = i - 1;
	st_a->data = (int*)malloc(sizeof(int) * i);
	st_b->data = (int*)malloc(sizeof(int) * i);
}

void	ft_puttab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
	{
		ft_putstr(tab[i]);
		ft_putstr("\n");
	}
}

void	ft_putarr(int *tab)
{
	int i;

	i = -1;
	while (tab[++i])
	{
		ft_putnbr(tab[i]);
		ft_putstr("\n");
	}
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
					fflush(stderr);
					return (1);
				}
			}
		}
	}
	return (0);
}

void	store(int ac, char **av)
{
	int			i;
	int			j;
	t_stack_a	st_a;
	t_stack_b	st_b;

		ft_putstr("\n\n\n\nstore(int ac, char **av)\n");
	i = -1;
	st_a.top = ac - 1;
	st_b.top = ac - 1;
	st_a.data = (int*)malloc(sizeof(int) * ac);
	st_b.data = (int*)malloc(sizeof(int) * ac);
	j = -1;
	while (++i <= st_a.top)
		st_a.data[i] = ft_atoi(av[i]);
	if (find_dup(&st_a) == 0)
		get_cmd(&st_a, &st_b);
	free(st_a.data);
	free(st_b.data);
}

void	number_error(char **av)
{
	int		ac;
	int		i;
	int		j;

	i = -1;
	ac = 0;
	while (av[ac])
		ac++;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j] != '\0')
			if (ft_isdigit(av[i][j]) == 0)
			{
				printf("tab[i][j] %s\n", av[i]);
				print_err("Argument is not a number\n");
				return ;
			}
		if (ft_atoli(av[i]) < -2147483648 && ft_atoli(av[i]) > 2147483647)
		{
			print_err("Number is out of range\n");
			return ;
		}
	}
	store(ac, av);
}

int		main(int ac, char **av)
{
	char	**tab;
	int		i;

	tab = NULL;
	if (ac >= 2)
	{
		if (ac == 2)
		{
			if (ft_strchr(av[1], '\t') != NULL)
				tab = ft_strsplit(av[1], '\t');
			else if (ft_strchr(av[1], ' ') != NULL)
				tab = ft_strsplit(av[1], ' ');
		}
		else if (ac > 2)
		{
			tab = av + 1;
			i = 0;
			while (++i < ac)
				tab[i - 1] = av[i];
				// printf("%d- tab[%s]\n", i, tab[i-1]);
		}
		printf("main %s\n",av[1]);
		number_error(tab);
	}
	return (0);
}
