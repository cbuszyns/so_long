/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuszyns <cbuszyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:28:08 by cbuszyns          #+#    #+#             */
/*   Updated: 2022/06/06 13:22:25 by cbuszyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_columns(t_vars *v)
{
	int	y;
	int	x;

	y = 0;
	while (v->mp[y])
	{
		x = 0;
		while (v->mp[y][x])
			x++;
		y++;
	}
	v->x = x;
}

void	count_row(t_vars *v)
{
	int	count;

	count = 0;
	while (v->mp[count])
		count++;
	v->y = count;
}

void	read_map(t_vars *v)
{
	char	*line;
	int		fd;

	fd = open(v->path, O_RDONLY);
	line = ft_get_next_line(fd);
	close (fd);
	v->mp = ft_split(line, '\n');
	count_row(v);
	count_columns(v);
	free(line);
}

void	put_map2(t_vars *v, int x, int y)
{
	if (v->mp[y][x] == 'E')
	{
		mlx_put_image_to_window(v->mx, v->w, v->m[4], x * 64, y * 64);
		v->e_x = x;
		v->e_y = y;
	}
	if (v->mp[y][x] == 'P')
	{
		v->px = x;
		v->py = y;
		mlx_put_image_to_window(v->mx, v->w, v->m[1], x * 64, y * 64);
	}
	if (v->mp[y][x] == 'C')
	{
		mlx_put_image_to_window(v->mx, v->w, v->m[3], x * 64, y * 64);
		v->coin++;
	}
	if (v->mp[y][x] == 'H')
		mlx_put_image_to_window(v->mx, v->w, v->m[8], x * 64, y * 64);
	return ;
}

void	put_map(t_vars *v)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	v->coin = 0;
	while (y < v->y)
	{
		x = 0;
		while (v->mp[y][x] != '\0')
		{
			mlx_put_image_to_window(v->mx, v->w, v->m[2], x * 64, y * 64);
			if (v->mp[y][x] == '1')
				mlx_put_image_to_window(v->mx, v->w, v->m[0], x * 64, y * 64);
			put_map2(v, x, y);
			x++;
		}
		y++;
	}
}
