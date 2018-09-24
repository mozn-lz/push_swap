/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msefako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 18:16:25 by msefako           #+#    #+#             */
/*   Updated: 2018/09/01 20:26:11 by msefako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct	s_stack_a
{
	int			*data;
	int			top;
}				t_stack_a;

typedef struct	s_stack_b
{
	int			*data;
	int			top;
}				t_stack_b;

void			fn_sa(t_stack_a *st_a);
void			fn_sb(t_stack_b *st_b);
void			fn_ss(t_stack_a *st_a, t_stack_b *st_b);
void			fn_ra(t_stack_a *st_a);
void			fn_rb(t_stack_b *st_b);
void			fn_rr(t_stack_a *st_a, t_stack_b *st_b);
void			fn_rra(t_stack_a *st_a);
void			fn_rrb(t_stack_b *st_b);
void			fn_rrr(t_stack_a *st_a, t_stack_b *st_b);
void			fn_pa(t_stack_a *st_a, t_stack_b *st_b);
void			fn_pb(t_stack_a *st_a, t_stack_b *st_b);
void			print_err(char *err);
char			**err_ctrl(int ac, char **av);
int				number_error(char **av, t_stack_a *st_a);
void			algo2(t_stack_a *st_a, t_stack_b *st_b,  char *cmd, int i);
int				ft_checker(t_stack_a *st_a, t_stack_b *st_b);
void	fn_print_stack(t_stack_a *st_a, t_stack_b *st_b);

#endif
