/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuszyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:29:20 by cbuszyns          #+#    #+#             */
/*   Updated: 2022/01/19 10:57:13 by cbuszyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	len2;
	char			*sub;

	if (s == NULL)
		return (NULL);
	i = 0;
	len2 = (unsigned int) len;
	if (ft_strlen(s) <= len)
		sub = (char *)malloc(ft_strlen(s) + 1);
	else
		sub = (char *)malloc(len2 + 1);
	if (!sub)
		return (NULL);
	if (!((unsigned int) ft_strlen(s) < start))
	{
		while (s[start] != '\0' && i < len2)
		{
			sub[i] = s[start];
			i++;
			start++;
		}
	}
	sub[i] = '\0';
	return (sub);
}
