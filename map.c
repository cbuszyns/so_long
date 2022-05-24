/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuszyns <cbuszyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:28:08 by cbuszyns          #+#    #+#             */
/*   Updated: 2022/05/24 13:01:45 by cbuszyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_columns(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
			x++;
		y++;
	}
	vars->x = x;
}

void	count_row(t_vars *vars)
{
	int	count;

	count = 0;
	while (vars->map[count])
		count++;
	vars->y = count;
}

void	read_map(t_vars *vars)
{
	char	*line;
	int		fd;

	fd = open(vars->path, O_RDONLY);
	line = ft_get_next_line(fd);
	close (fd);
	vars->map = ft_split(line, '\n');
	count_row(vars);
	count_columns(vars);
}

void	put_map(t_vars *vars)
{
	int x;
	int y;

	x = 0;
	y = 0;
	vars->coin = 0;
	while(y < vars->y)
	{
		x = 0;
		while(vars->map[y][x] != '\0')
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], x * 64, y * 64);
			if(vars->map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img[0], x * 64, y * 64);
			if(vars->map[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img[4], x * 64, y * 64);
			if(vars->map[y][x] == 'P')
			{
				vars->player_x = x;
				vars->player_y = y;
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img[1], x * 64, y * 64);
			}
			if(vars->map[y][x] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img[3], x * 64, y * 64);
				vars->coin++;
			}
			x++;
		}
		y++;
	}
}

