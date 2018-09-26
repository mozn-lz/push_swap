#include "../includes/push_swap.h"

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
				// ft_putstr("A sort ERROR\n");
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

void	algo2(t_stack_a *s_a, t_stack_b *s_b,  char *cmd, int i)
{
	if ((s_a->top > -1) && (ft_checker(s_a, s_b) == 0))
	{
		if (s_a->data[s_a->top - 1] < s_a->data[s_a->top])
		{
			ft_putstr("O1---fn_sa\n");
			fn_sa(s_a);
			cmd[++i] = *ft_strdup("sa\n");
			// fn_print_stack(s_a, s_b);
		}
		else if (s_a->data[0] < s_a->data[s_a->top])
		{
			ft_putstr("O2---fn_ra\n");
			fn_ra(s_a);
			cmd[++i] = *ft_strdup("ra\n");
			// fn_print_stack(s_a, s_b);
		}
		// else if (s_a->data[0] > s_a->data[s_a->top])
		// {
		// 	ft_putstr("O3---fn_rra\n");
		// 	fn_rra(s_a);
		// 	cmd[++i] = *ft_strdup("rra\n");
		// }
		else if ((ft_check_a(s_a) == 0) && (s_a->top > -1))
		{
			ft_putstr("O4---fn_pb\n");
			fn_pb(s_a, s_b);
			cmd[++i] = *ft_strdup("pb\n");
			// fn_print_stack(s_a, s_b);
		}


		if (s_b->top > -1)
		{
			ft_putstr("{ B\n");
			if (s_b->data[s_b->top - 1] > s_b->data[s_b->top])
			{
				ft_putstr("O5---fn_sb\n");
				fn_sb(s_b);
				cmd[++i] = *ft_strdup("sb\n");
				// fn_print_stack(s_a, s_b);
			}
			else if (s_b->data[0] > s_b->data[s_b->top])
			{
				ft_putstr("O6---fn_rb\n");
				fn_rb(s_b);
				cmd[++i] = *ft_strdup("rb\n");
				// fn_print_stack(s_a, s_b);
			}
			// else if (s_b->data[0] < s_b->data[s_b->top])
			// {
			// 	ft_putstr("O7---fn_rrb\n");
			// 	fn_rrb(s_b);
			// 	cmd[++i] = *ft_strdup("rrb\n");
			// 	fn_print_stack(s_a, s_b);
			// }
			else if (ft_check_a(s_a) == 1)
			{
				ft_putstr("O8---fn_pa\n");
				fn_pa(s_a, s_b);
				cmd[++i] = *ft_strdup("pa\n");
				// fn_print_stack(s_a, s_b);
			}
		}
	}
}
		// else if (ft_stack_checker(s_a, s_b) == 1)
		// {
		// 	ft_putstr("stack  checker works O1\n");
		// 	if (ft_checker(s_a, s_b) == 1)
		// 		return ;
		// 	else
		// 	{
		// 	ft_putstr("Recurse O2\n");
		// 		fn_pa(s_a, s_b);
		// 		algo2(s_a, s_b, cmd, 1);
		// 	}
		// }
		// else if ((s_b->top > -1 && s_a->data) && (ft_check_a(s_a) == 1))
		// else if ((s_a->data[s_a->top] < s_a->data[s_a->top - 1]) &&
		// 		(s_a->data[s_a->top] < s_a->data[0]) && (ft_check_a(s_a) == 0))

		// else if (!(s_a->data[0] < s_a->data[s_a->top]))

// 	if (s_a->top <= -1)
// 	{
// ft_putstr("P\n");
// 		fn_pa(s_a, s_b);
// 		cmd[++i] = *ft_strdup("pa\n");
// 	fn_print_stack(s_a, s_b);
// 	}
// 	if (ft_stack_checker(s_a, s_b) == 1)
// 		algo2(s_a, s_b, cmd, 1);
// 	else if (ft_stack_checker(s_a, s_b) == 0)
// 	{
// ft_putstr("O1\n");
// 		if (ft_checker(s_a, s_b) == 1)
// 			return ;
// 		else
// 		{
// ft_putstr("O2\n");
// 			fn_pa(s_a, s_b);
// 			algo2(s_a, s_b, cmd, 1);
// 		}
// 	}