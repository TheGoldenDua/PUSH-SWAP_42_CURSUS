/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:37:57 by del-ganb          #+#    #+#             */
/*   Updated: 2024/08/18 19:43:05 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_elem_in_range(t_stack *a, t_data *ctrl)
{
	int	i;
	int	pos;

	pos = 0;
	while (a)
	{
		i = ctrl->start;
		while (i <= ctrl->end)
		{
			if (ctrl->sorted_arr[i] == a->data)
				return (pos);
			i++;
		}
		a = a->next;
		pos++;
	}
	return (-1);
}

t_data	*adjust_ctrl(t_data *ctrl)
{
	ctrl->start -= ctrl->offset;
	if (ctrl->start < 0)
		ctrl->start = 0;
	ctrl->end += ctrl->offset;
	if (ctrl->end > ctrl->size - 1)
		ctrl->end = ctrl->size - 1;
	return (ctrl);
}

int	contains_value_in_range(t_stack *a, t_data *ctrl)
{
	int	i;

	i = 0;
	while (i < ctrl->size)
	{
		if (a->data == ctrl->sorted_arr[i])
			break ;
		i++;
	}
	while (a)
	{
		if (i > 0 && ctrl->sorted_arr[i - 1] == a->data)
			return (1);
		a = a->next;
	}
	return (0);
}

int	in_correct_pos(t_stack *a, t_stack *b, t_data *ctrl)
{
	int	i;

	i = 0;
	while (i < ctrl->size)
	{
		if (a->data == ctrl->sorted_arr[i])
			break ;
		i++;
	}
	if (i > 0 && b->data == ctrl->sorted_arr[i - 1])
		return (1);
	return (0);
}

void	back_to_a(t_stack **a, t_stack **b, t_data *ctrl)
{
	int	pos;
	int	n;

	if (!a || !b || !ctrl || !ctrl->sorted_arr)
		return ;
	pos = max_pos(*b);
	a_peak(b, a, pos);
	while (*b)
	{
		if (contains_value_in_range(*a, ctrl))
			rra(a);
		else if (in_correct_pos(*a, *b, ctrl))
			push_to(b, a, 'a');
		else if (is_max_at_end(*a, ctrl->sorted_arr[ctrl->size - 1])
			|| is_greater((*b)->data, *a))
		{
			push_to(b, a, 'a');
			ra(a);
		}
		else
		{
			n = get_biggest(*b, 1);
			adjust_position(b, n, get_biggest(*b, 2));
		}
	}
}
