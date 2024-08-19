/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:07:09 by del-ganb          #+#    #+#             */
/*   Updated: 2024/08/17 22:21:53 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static void	display_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	res;
	int		signe;

	i = 0;
	signe = 1;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			signe *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	if ((res * signe) < INT_MIN || (res * signe) > INT_MAX)
		display_error();
	return (res * signe);
}
