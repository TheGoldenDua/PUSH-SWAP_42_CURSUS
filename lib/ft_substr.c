/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:18:24 by del-ganb          #+#    #+#             */
/*   Updated: 2023/11/15 15:44:42 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	while (i + start < s_len && i < len)
		i++;
	res = (char *)malloc((i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	s_len = 0;
	while (i > 0)
	{
		res[s_len] = s[start];
		s_len++;
		start++;
		i--;
	}
	res[s_len] = '\0';
	return (res);
}
