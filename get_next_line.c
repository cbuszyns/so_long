/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuszyns <cbuszyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:49:15 by cbuszyns          #+#    #+#             */
/*   Updated: 2022/06/06 15:09:21 by cbuszyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin2(char *s, char c)
{
	int		i;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	new = (char *) malloc (sizeof(char) * (ft_strlen(s) + 2));
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i++] = c;
	new[i] = '\0';
	free(s);
	return (new);
}

char	*ft_read_line(int fd, char *dst)
{
	int		len;
	char	buf;

	len = 1;
	while (len != 0)
	{
		len = read(fd, &buf, 1);
		if (len == -1)
			return (NULL);
		dst = ft_strjoin2(dst, buf);
	}
	if (dst[0] == '\0')
		return ("\0");
	if (!dst[1])
		return (NULL);
	return (dst);
}

char	*ft_get_next_line(int fd)
{
	char	*dst;

	if (fd < 0)
		return (NULL);
	dst = (char *) malloc (sizeof(char) * 1);
	if (!dst)
		return (NULL);
	dst[0] = '\0';
	dst = ft_read_line(fd, dst);
	if (!dst)
		return (NULL);
	return (dst);
}
