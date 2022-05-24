/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuszyns <cbuszyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:00:21 by cbuszyns          #+#    #+#             */
/*   Updated: 2022/05/24 12:50:39 by cbuszyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	keypress(int keycode, t_vars *vars)
{
	if (keycode == 53 || keycode == 12)
		ft_close(vars);
	if (keycode == 13 || keycode == 126)
		move_up(vars);
	else if (keycode == 0 || keycode == 123)
		move_left(vars);
	else if (keycode == 1 || keycode == 125)
		move_down(vars);
	else if (keycode == 2 || keycode == 124)
		move_right(vars);
	return (0);
}

void	load_img(t_vars	*vars)
{
	int	x;
	int	y;

	vars->path_to_img = (void **)malloc(sizeof(void **) * 5);
	vars->img = (void **)malloc(sizeof(void **) * 5);
	vars->path_to_img[0] = "./Sprites/wall.xpm";
	vars->path_to_img[1] = "./Sprites/player.xpm";
	vars->path_to_img[2] = "./Sprites/floor.xpm";
	vars->path_to_img[3] = "./Sprites/coin.xpm";
	vars->path_to_img[4] = "./Sprites/exit.xpm";

	vars->img[0] = mlx_xpm_file_to_image(vars->mlx, vars->path_to_img[0], &x, &y);
	vars->img[1] = mlx_xpm_file_to_image(vars->mlx, vars->path_to_img[1], &x, &y);
	vars->img[2] = mlx_xpm_file_to_image(vars->mlx, vars->path_to_img[2], &x, &y);
	vars->img[3] = mlx_xpm_file_to_image(vars->mlx, vars->path_to_img[3], &x, &y);
	vars->img[4] = mlx_xpm_file_to_image(vars->mlx, vars->path_to_img[4], &x, &y);
}

int	main(int argc, char **argv)
{
	t_vars 	vars;

	if(argc == 1)
		return (0);
	vars.path = argv[1];
	read_map(&vars);
	check_elements(&vars);
	check_walls(&vars);
	vars.mlx = mlx_init();
	load_img(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.x * 64, vars.y * 64, "voglio morire");
	put_map(&vars);
	mlx_hook(vars.win, 2, 1L<<0, keypress, &vars);
	mlx_loop(vars.mlx);
}


// ESC : 53
// W : 13
// A : 0
// S : 1
// D : 2
// E : 14
// Q : 12
// ENTER : 36
// FRECCIA DX : 123
// FRECCIA SX : 124
// FRECCIA GIÙ : 125
// FRECCIA SU : 126
// SHIFT SX : 257
// SHIFT DX : 258
// CTRL SX : 256
// CTRL DX : 269
// SPACE : 49
// M : 46
// F : 3
// R : 15
