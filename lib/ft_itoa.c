/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 03:07:20 by del-ganb          #+#    #+#             */
/*   Updated: 2023/11/21 23:45:47 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_digit(long n)
{
	int	c_digit;

	c_digit = 0;
	if (n < 0)
	{
		c_digit++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		c_digit++;
	}
	return (c_digit);
}

static	char	*is_zero(char *tab)
{
	tab = (char *)malloc(2 * sizeof(char));
	if (!tab)
		return (NULL);
	tab[0] = '0';
	tab[1] = '\0';
	return (tab);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*res;
	size_t	c_digit;

	nb = n;
	res = NULL;
	if (nb == 0)
		return (is_zero(res));
	c_digit = count_digit(nb);
	res = (char *)malloc((c_digit + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[c_digit--] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		res[0] = '-';
	}
	while (nb > 0)
	{
		res[c_digit] = (nb % 10) + '0';
		nb /= 10;
		c_digit--;
	}
	return (res);
}
