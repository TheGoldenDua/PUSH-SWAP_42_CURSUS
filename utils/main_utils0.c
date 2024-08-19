/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:38:11 by del-ganb          #+#    #+#             */
/*   Updated: 2024/08/17 16:38:12 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	clear_list(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*next_node;

	curr = *stack;
	while (curr)
	{
		next_node = curr->next;
		free(curr);
		curr = next_node;
	}
	*stack = NULL;
}

int	check_dup(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*next_node;

	curr = stack;
	while (curr)
	{
		next_node = curr->next;
		while (next_node)
		{
			if (curr->data == next_node->data)
				return (0);
			next_node = next_node->next;
		}
		curr = curr->next;
	}
	return (1);
}

void	add_to_stack(char *str, t_stack **stack)
{
	if (!is_valid_num(str))
	{
		clear_list(stack);
		display_error();
	}
	push(stack, ft_atoi(str));
}

int	is_sorted(t_stack *stack)
{
	t_stack	*next_node;

	if (!stack)
		return (0);
	while (stack && stack->next)
	{
		next_node = stack->next;
		if (stack->data > next_node->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	start_point(t_stack **a, t_stack **b)
{
	if (count_nodes(*a) == 2)
		sa(a);
	else if (count_nodes(*a) == 3)
		sort_three(a);
	else if (count_nodes(*a) == 5 || count_nodes(*a) == 4)
		sort_five(a, b);
	else
		big_sort(a, b);
}
