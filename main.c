/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:37:07 by del-ganb          #+#    #+#             */
/*   Updated: 2024/08/17 16:37:08 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	check_args(char *str, t_stack **a)
{
	int		i;
	char	**res;

	i = 0;
	if (ft_strchr(str, ' '))
	{
		res = ft_split(str, ' ');
		if (!res)
		{
			clear_list(a);
			display_error();
			free(res);
		}
		while (res[i])
		{
			add_to_stack(res[i], a);
			free(res[i]);
			i++;
		}
		free(res);
	}
	else
		add_to_stack(str, a);
}

void	parsing(int argc, char **argv, t_stack **a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		check_args(argv[i], a);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	parsing(argc, argv, &a);
	if (!check_dup(a))
	{
		clear_list(&a);
		display_error();
	}
	if (is_sorted(a))
	{
		clear_list(&a);
		return (0);
	}
	start_point(&a, &b);
	clear_list(&a);
	return (0);
}
