/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:08:50 by del-ganb          #+#    #+#             */
/*   Updated: 2023/11/24 21:03:03 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len > 0)
	{
		if (s[len] == (unsigned char)c)
		{
			return ((char *)&s[len]);
		}
		len--;
	}
	if ((unsigned char)c == s[len])
		return ((char *)&s[len]);
	return (NULL);
}
