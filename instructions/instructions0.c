/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:37:20 by del-ganb          #+#    #+#             */
/*   Updated: 2024/08/17 16:37:21 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **a)
{
	int	c_n;

	c_n = count_nodes(*a);
	if (c_n >= 2)
	{
		swap(&(*a)->data, &(*a)->next->data);
		ft_putstr_fd("sa\n", 1);
	}
}

void	sb(t_stack **b)
{
	int	c_n;

	c_n = count_nodes(*b);
	if (c_n >= 2)
	{
		swap(&(*b)->data, &(*b)->next->data);
		ft_putstr_fd("sb\n", 1);
	}
}

void	ss(t_stack **a, t_stack **b)
{
	int	ac_n;
	int	bc_n;

	ac_n = count_nodes(*a);
	bc_n = count_nodes(*b);
	if (ac_n >= 2)
		swap(&(*a)->data, &(*a)->next->data);
	if (bc_n >= 2)
		swap(&(*b)->data, &(*b)->next->data);
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_stack **a, t_stack **b)
{
	if (count_nodes(*b))
	{
		push(a, pop(b));
		ft_putstr_fd("pa\n", 1);
	}
}

void	pb(t_stack **a, t_stack **b)
{
	if (count_nodes(*a))
	{
		push(b, pop(a));
		ft_putstr_fd("pb\n", 1);
	}
}
