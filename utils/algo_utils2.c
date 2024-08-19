/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:38:00 by del-ganb          #+#    #+#             */
/*   Updated: 2024/08/18 17:55:21 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_max_at_end(t_stack *a, int max)
{
	while (a->next)
		a = a->next;
	if (a->data == max)
		return (1);
	return (0);
}

int	is_greater(int b_val, t_stack *a)
{
	while (a->next)
		a = a->next;
	if (b_val > a->data)
		return (1);
	return (0);
}

int	get_biggest(t_stack *b, int ret_pos)
{
	int	pos;
	int	max;
	int	i;

	max = b->data;
	pos = 0;
	i = 0;
	while (b)
	{
		if (b->data > max)
		{
			pos = i;
			max = b->data;
		}
		i++;
		b = b->next;
	}
	if (ret_pos == 1)
		return (pos);
	return (max);
}

void	adjust_position(t_stack **b, int pos, int num)
{
	int	size;

	size = count_nodes(*b);
	if (size - pos + 1 <= pos)
	{
		while ((*b)->data != num)
			rrb(b);
	}
	else
	{
		while ((*b)->data != num)
			rb(b);
	}
}

t_data	*ctrl_init(int size, int div)
{
	t_data	*ctrl;

	ctrl = (t_data *)malloc(sizeof(t_data));
	if (!ctrl)
		return (NULL);
	ctrl->size = size;
	ctrl->div = div;
	ctrl->mid = size / 2;
	ctrl->offset = size / div;
	ctrl->start = ctrl->mid - ctrl->offset;
	ctrl->end = ctrl->mid + ctrl->offset;
	ctrl->sorted_arr = (int *)malloc(size * sizeof(int));
	if (!ctrl->sorted_arr)
	{
		free(ctrl);
		return (NULL);
	}
	return (ctrl);
}
