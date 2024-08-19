/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:37:43 by del-ganb          #+#    #+#             */
/*   Updated: 2024/08/18 19:42:03 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;
	int	swapped;

	i = 0;
	while (i < size - 1)
	{
		swapped = 0;
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break ;
		i++;
	}
}

int	within_range(t_data *ctrl, int elem)
{
	int	i;

	i = ctrl->start;
	while (i <= ctrl->end)
	{
		if (elem == ctrl->sorted_arr[i])
			return (1);
		i++;
	}
	return (0);
}

void	process_stack(t_stack **a, t_stack **b, t_data *ctrl)
{
	int	pos;

	if (within_range(ctrl, (*a)->data))
	{
		push_to(a, b, 'b');
		if ((*b)->data < ctrl->sorted_arr[ctrl->mid])
			rb(b);
	}
	else
	{
		pos = get_elem_in_range(*a, ctrl);
		if (pos != -1)
		{
			b_peak(a, b, pos);
			if ((*b)->data < ctrl->sorted_arr[ctrl->mid])
				rb(b);
		}
		else
		{
			ctrl = adjust_ctrl(ctrl);
		}
	}
}

void	process_and_sort(t_stack **a, t_stack **b, t_data *ctrl)
{
	while (*a)
	{
		process_stack(a, b, ctrl);
	}
	back_to_a(a, b, ctrl);
	while (!is_sorted(*a))
		rra(a);
}
