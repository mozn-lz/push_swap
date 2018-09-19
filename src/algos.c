#include "../includes/push_swap.h"

/*	
	13 steps
	sa		sb		ss
	pa		pb
	ra		rb		rr
	rra		rrb		rrr
*/
char	algo1(t_stack_a *st_a)
{
	char	process;
	int i = 0;
	if (sa[0] > sa[0 + 1])
	{
		ft_sa();
	}
	else if (sa[0] > sa[max])
	{
		ft_rra();
	}
	else if (sa[0] < sa[max])
	{
		ft_ra();
	}
	else if (sa[0] < sa[max] && sa[0 + 1] > sa[max])
	{
		ft_ra();
		ft_sa();
	}
	else if (ft_stack_checker() != 1)
	{
		ft_pb();
		algo1();
	}
	else
	{
		if (ft_checker() != 1 && st_b->top >-1)
		{
			ft_pb();
			algo1();
			ft_checker() == 1 ?  "step(s) done above && stop" : "step(s) done above && continue";
		}
		else if (ft_checker() == 1)
		{
			"step(s) done above && stop";
		}
	}
}