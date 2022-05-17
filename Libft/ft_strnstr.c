/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuszyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:28:14 by cbuszyns          #+#    #+#             */
/*   Updated: 2022/01/18 12:50:42 by cbuszyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcmp(char *a, char *b, size_t pos)
{
	size_t	j;

	j = 0;
	while (a[pos] == b[j] && a[pos] != '\0' && b[j] != '\0')
	{
		pos++;
		j++;
	}
	if (b[j] == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	size_n;
	int		b;

	i = 0;
	size_n = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			if ((len - i) >= size_n || size_n == 1)
			{
				b = ft_strcmp((char *)haystack, (char *)needle, i);
				if (b == 1)
					return ((char *)haystack + i);
			}
		}
		i++;
	}
	return (NULL);
}
