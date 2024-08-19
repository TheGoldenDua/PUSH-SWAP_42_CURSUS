/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_func0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:38:21 by del-ganb          #+#    #+#             */
/*   Updated: 2024/08/18 17:57:48 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **stack)
{
	int	pos;

	pos = max_pos(*stack);
	if (pos == 0)
		ra(stack);
	else if (pos == 1)
		rra(stack);
	if (!is_sorted(*stack))
		sa(stack);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	pos;
	int	len;

	len = count_nodes(*a);
	while (len > 3)
	{
		pos = min_pos(*a);
		b_peak(a, b, pos);
		len--;
	}
	sort_three(a);
	while (*b)
		push_to(b, a, 'a');
}

void	big_sort(t_stack **a, t_stack **b)
{
	t_data	*ctrl;
	int		i;
	t_stack	*curr;
	int		size;

	curr = *a;
	size = count_nodes(*a);
	ctrl = ctrl_init(size, ft_sqrt(size));
	if (!ctrl)
		return ;
	i = 0;
	while (i < size)
	{
		ctrl->sorted_arr[i] = curr->data;
		i++;
		curr = curr->next;
	}
	bubble_sort(ctrl->sorted_arr, size);
	process_and_sort(a, b, ctrl);
	free(ctrl->sorted_arr);
	free(ctrl);
}
