/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuszyns <cbuszyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:48:00 by cbuszyns          #+#    #+#             */
/*   Updated: 2022/05/17 16:39:45 by cbuszyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *vars)
{
	vars->steps++;
	ft_printf("Steps: %d\n", vars->steps);
	if (vars->map[vars->player_y - 1][vars->player_x] == '1')
		return ;
	if (vars->map[vars->player_y - 1][vars->player_x] == 'E' && vars->coin == 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], vars->player_x * 64, vars->player_y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img[1], vars->player_x * 64, (vars->player_y - 1) * 64);
		ft_close(vars);
	}
	else if (vars->map[vars->player_y - 1][vars->player_x] == 'E' && vars->coin > 0)
		return ;
	if (vars->map[vars->player_y - 1][vars->player_x] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], vars->player_x * 64, vars->player_y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], vars->player_x * 64, (vars->player_y - 1) * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img[1], vars->player_x * 64, (vars->player_y - 1) * 64);
		vars->map[vars->player_y - 1][vars->player_x] = '0';
		vars->coin--;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], vars->player_x * 64, vars->player_y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[1], vars->player_x * 64, (vars->player_y - 1) * 64);
	vars->player_y--;
}

void	move_down(t_vars *vars)
{
	vars->steps++;
	ft_printf("Steps: %d\n", vars->steps);
	if (vars->map[vars->player_y + 1][vars->player_x] == '1')
		return ;
	if (vars->map[vars->player_y + 1][vars->player_x] == 'E' && vars->coin == 0)
		ft_close(vars);
	else if (vars->map[vars->player_y + 1][vars->player_x] == 'E' && vars->coin > 0)
		return ;
	if (vars->map[vars->player_y + 1][vars->player_x] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], vars->player_x * 64, vars->player_y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], vars->player_x * 64, (vars->player_y + 1) * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img[1], vars->player_x * 64, (vars->player_y + 1) * 64);
		vars->map[vars->player_y + 1][vars->player_x] = '0';
		vars->coin--;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], vars->player_x * 64, vars->player_y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[1], vars->player_x * 64, (vars->player_y + 1) * 64);
	vars->player_y++;
}

void	move_left(t_vars *vars)
{
	vars->steps++;
	ft_printf("Steps: %d\n", vars->steps);
	if (vars->map[vars->player_y][vars->player_x - 1] == '1')
		return ;
	if (vars->map[vars->player_y][vars->player_x - 1] == 'E' && vars->coin == 0)
		ft_close(vars);
	else if (vars->map[vars->player_y][vars->player_x - 1] == 'E' && vars->coin > 0)
		return ;
	if (vars->map[vars->player_y][vars->player_x - 1] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], vars->player_x * 64, vars->player_y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], (vars->player_x - 1) * 64, vars->player_y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img[1], (vars->player_x - 1) * 64, vars->player_y * 64);
		vars->map[vars->player_y][vars->player_x - 1] = '0';
		vars->coin--;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], vars->player_x * 64, vars->player_y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[1], (vars->player_x - 1) * 64, vars->player_y * 64);
	vars->player_x--;
}

void	move_right(t_vars *vars)
{
	vars->steps++;
	ft_printf("Steps: %d\n", vars->steps);
	if (vars->map[vars->player_y][vars->player_x + 1] == '1')
		return ;
	if (vars->map[vars->player_y][vars->player_x + 1] == 'E' && vars->coin == 0)
		ft_close(vars);
	else if (vars->map[vars->player_y][vars->player_x + 1] == 'E' && vars->coin > 0)
		return ;
	if (vars->map[vars->player_y][vars->player_x + 1] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], vars->player_x * 64, vars->player_y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], (vars->player_x + 1) * 64, vars->player_y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img[1], (vars->player_x + 1) * 64, vars->player_y * 64);
		vars->map[vars->player_y][vars->player_x + 1] = '0';
		vars->coin--;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], vars->player_x * 64, vars->player_y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[1], (vars->player_x + 1) * 64, vars->player_y * 64);
	vars->player_x++;
}

