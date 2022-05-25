/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuszyns <cbuszyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:48:00 by cbuszyns          #+#    #+#             */
/*   Updated: 2022/05/25 15:14:23 by cbuszyns         ###   ########.fr       */
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
		ft_printf("You Won!\n");
		ft_close(vars);
	}
	else if (vars->map[vars->player_y - 1][vars->player_x] == 'E' && vars->coin > 0)
		return ;
	if (vars->map[vars->player_y - 1][vars->player_x] == 'C')
	{
		vars->map[vars->player_y - 1][vars->player_x] = '0';
		vars->coin--;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], vars->player_x * 64, vars->player_y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], vars->player_x * 64, (vars->player_y - 1) * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[5], vars->player_x * 64, (vars->player_y - 1) * 64);
	vars->player_y--;
}

void	move_down(t_vars *vars)
{
	vars->steps++;
	ft_printf("Steps: %d\n", vars->steps);
	if (vars->map[vars->player_y + 1][vars->player_x] == '1')
		return ;
	if (vars->map[vars->player_y + 1][vars->player_x] == 'E' && vars->coin == 0)
	{
		ft_printf("You Won!\n");
		ft_close(vars);
	}
	else if (vars->map[vars->player_y + 1][vars->player_x] == 'E' && vars->coin > 0)
		return ;
	if (vars->map[vars->player_y + 1][vars->player_x] == 'C')
	{
		vars->map[vars->player_y + 1][vars->player_x] = '0';
		vars->coin--;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], vars->player_x * 64, vars->player_y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], vars->player_x * 64, (vars->player_y + 1) * 64);
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
	{
		ft_printf("You Won!\n");
		ft_close(vars);
	}
	else if (vars->map[vars->player_y][vars->player_x - 1] == 'E' && vars->coin > 0)
		return ;
	if (vars->map[vars->player_y][vars->player_x - 1] == 'C')
	{
		vars->map[vars->player_y][vars->player_x - 1] = '0';
		vars->coin--;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], vars->player_x * 64, vars->player_y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], (vars->player_x - 1) * 64, vars->player_y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[7], (vars->player_x - 1) * 64, vars->player_y * 64);
	vars->player_x--;
}

void	move_right(t_vars *vars)
{
	vars->steps++;
	ft_printf("Steps: %d\n", vars->steps);
	if (vars->map[vars->player_y][vars->player_x + 1] == '1')
		return ;
	if (vars->map[vars->player_y][vars->player_x + 1] == 'E' && vars->coin == 0)
	{
		ft_printf("You Won!\n");
		ft_close(vars);
	}
	else if (vars->map[vars->player_y][vars->player_x + 1] == 'E' && vars->coin > 0)
		return ;
	if (vars->map[vars->player_y][vars->player_x + 1] == 'C')
	{
		vars->map[vars->player_y][vars->player_x + 1] = '0';
		vars->coin--;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], vars->player_x * 64, vars->player_y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], (vars->player_x + 1) * 64, vars->player_y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[6], (vars->player_x + 1) * 64, vars->player_y * 64);
	vars->player_x++;
}

