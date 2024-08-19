/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:37:29 by del-ganb          #+#    #+#             */
/*   Updated: 2024/08/17 16:37:30 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*top;
	t_stack	*bottom;
	int		c_n;

	c_n = count_nodes(*a);
	if (c_n >= 2)
	{
		top = *a;
		bottom = s_bottom(*a);
		*a = top->next;
		(*a)->prev = NULL;
		top->next = NULL;
		top->prev = bottom;
		bottom->next = top;
		ft_putstr_fd("ra\n", 1);
	}
}

void	rb(t_stack **b)
{
	t_stack	*top;
	t_stack	*bottom;
	int		c_n;

	c_n = count_nodes(*b);
	if (c_n >= 2)
	{
		top = *b;
		bottom = s_bottom(*b);
		*b = top->next;
		(*b)->prev = NULL;
		top->next = NULL;
		top->prev = bottom;
		bottom->next = top;
		ft_putstr_fd("rb\n", 1);
	}
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack **a)
{
	t_stack	*bottom;
	t_stack	*before_bottom;

	if (count_nodes(*a) >= 2)
	{
		bottom = s_bottom(*a);
		before_bottom = bottom->prev;
		if (before_bottom)
			before_bottom->next = NULL;
		bottom->prev = NULL;
		bottom->next = *a;
		(*a)->prev = bottom;
		*a = bottom;
		ft_putstr_fd("rra\n", 1);
	}
}

void	rrb(t_stack **b)
{
	t_stack	*bottom;
	t_stack	*before_bottom;

	if (count_nodes(*b) >= 2)
	{
		bottom = s_bottom(*b);
		before_bottom = bottom->prev;
		if (before_bottom)
			before_bottom->next = NULL;
		bottom->prev = NULL;
		bottom->next = *b;
		(*b)->prev = bottom;
		*b = bottom;
		ft_putstr_fd("rrb\n", 1);
	}
}
