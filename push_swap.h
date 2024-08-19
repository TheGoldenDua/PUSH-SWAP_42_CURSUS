/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:38:39 by del-ganb          #+#    #+#             */
/*   Updated: 2024/08/18 19:42:23 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_data
{
	int				size;
	int				*sorted_arr;
	int				div;
	int				mid;
	int				offset;
	int				start;
	int				end;

}					t_data;

int					count_nodes(t_stack *head);
t_stack				*create_node(int n);
void				swap(int *a, int *b);
t_stack				*s_bottom(t_stack *stack);
void				push(t_stack **stack, int value);
int					pop(t_stack **stack);
void				clear_list(t_stack **stack);
int					check_dup(t_stack *stack);
void				add_to_stack(char *str, t_stack **stack);
int					is_sorted(t_stack *stack);
void				start_point(t_stack **a, t_stack **b);
int					ft_atoi(const char *str);
int					check_digit(char *str);
int					is_valid_num(char *str);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
int					max_pos(t_stack *stack_b);
int					min_pos(t_stack *stack_a);
void				push_to(t_stack **s_from, t_stack **s_to, char s_name);
void				b_peak(t_stack **a, t_stack **b, int pos);
void				a_peak(t_stack **b, t_stack **a, int pos);
void				sort_three(t_stack **stack);
void				sort_five(t_stack **a, t_stack **b);
void				display_error(void);
void				check_args(char *str, t_stack **a);
void				parsing(int argc, char **argv, t_stack **a);
int					ft_sqrt(int nb);
void				bubble_sort(int *arr, int size);
t_data				*ctrl_init(int size, int div);
int					within_range(t_data *ctrl, int elem);
void				process_stack(t_stack **a, t_stack **b, t_data *ctrl);
void				process_and_sort(t_stack **a, t_stack **b, t_data *ctrl);
int					get_elem_in_range(t_stack *a, t_data *ctrl);
t_data				*adjust_ctrl(t_data *ctrl);
int					contains_value_in_range(t_stack *a, t_data *ctrl);
int					in_correct_pos(t_stack *a, t_stack *b, t_data *ctrl);
void				back_to_a(t_stack **a, t_stack **b, t_data *ctrl);
int					is_max_at_end(t_stack *a, int max);
int					is_greater(int b_val, t_stack *a);
int					get_biggest(t_stack *b, int ret_pos);
void				adjust_position(t_stack **b, int pos, int num);
void				big_sort(t_stack **a, t_stack **b);
#endif