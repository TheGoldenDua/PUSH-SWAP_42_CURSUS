/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_func_utils0.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:38:18 by del-ganb          #+#    #+#             */
/*   Updated: 2024/08/18 18:59:28 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max_pos(t_stack *stack_b)
{
	int	max;
	int	pos;
	int	i;

	max = INT_MIN;
	pos = 0;
	i = 0;
	while (stack_b)
	{
		if (stack_b->data > max)
		{
			max = stack_b->data;
			pos = i;
		}
		stack_b = stack_b->next;
		i++;
	}
	return (pos);
}

int	min_pos(t_stack *stack_a)
{
	int	min;
	int	pos;
	int	i;

	min = INT_MAX;
	pos = 0;
	i = 0;
	while (stack_a)
	{
		if (stack_a->data < min)
		{
			min = stack_a->data;
			pos = i;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (pos);
}

void	push_to(t_stack **s_from, t_stack **s_to, char s_name)
{
	int		value;
	t_stack	*new_node;

	if (!*s_from)
		return ;
	value = pop(s_from);
	new_node = create_node(value);
	if (!new_node)
		return ;
	new_node->next = *s_to;
	if (*s_to)
		(*s_to)->prev = new_node;
	*s_to = new_node;
	ft_putchar_fd('p', 1);
	ft_putchar_fd(s_name, 1);
	ft_putchar_fd('\n', 1);
}

void	b_peak(t_stack **a, t_stack **b, int pos)
{
	int	len;

	len = count_nodes(*a);
	if (pos >= len / 2)
	{
		while (pos++ < len)
			rra(a);
	}
	else
	{
		while (pos-- > 0)
			ra(a);
	}
	push_to(a, b, 'b');
}

void	a_peak(t_stack **b, t_stack **a, int pos)
{
	int	len;

	len = count_nodes(*b);
	if (pos >= len / 2)
	{
		while (pos++ < len)
			rrb(b);
	}
	else
	{
		while (pos-- > 0)
			rb(b);
	}
	push_to(b, a, 'a');
}
