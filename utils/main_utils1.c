/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:38:15 by del-ganb          #+#    #+#             */
/*   Updated: 2024/08/17 21:52:09 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_valid_num(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] == 32 || (i[str] >= 9 && i[str] <= 13))
		i++;
	if (i[str] == '-' || i[str] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (i[str] == '0')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(i[str]))
			return (0);
		i++;
		j++;
	}
	if (ft_strlen(&str[i - j]) > 10)
		return (0);
	return (1);
}
