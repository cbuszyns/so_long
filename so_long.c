/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuszyns <cbuszyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:00:21 by cbuszyns          #+#    #+#             */
/*   Updated: 2022/06/06 13:03:14 by cbuszyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_vars *v)
{
	mlx_destroy_window(v->mx, v->w);
	exit(0);
	return (0);
}

void	display_moves(t_vars *v)
{
	char	*moves;

	moves = ft_itoa(v->steps);
	mlx_put_image_to_window(v->mx, v->w, v->m[0], 1 * 64, 0 * 64);
	mlx_put_image_to_window(v->mx, v->w, v->m[0], 0 * 64, 0 * 64);
	mlx_string_put(v->mx, v->w, 90, 20, 0, moves);
	mlx_string_put(v->mx, v->w, 20, 20, 0, "Moves :");
	free(moves);
}

int	keypress(int keycode, t_vars *v)
{
	if (keycode == 53 || keycode == 12)
		ft_close(v);
	if (keycode == 13 || keycode == 126)
		move_up(v);
	else if (keycode == 0 || keycode == 123)
		move_left(v);
	else if (keycode == 1 || keycode == 125)
		move_down(v);
	else if (keycode == 2 || keycode == 124)
		move_right(v);
	return (0);
}

void	load_img(t_vars	*v)
{
	int	x;
	int	y;

	v->path_img = (char **)malloc(sizeof(char *) * 10);
	v->m = (void **)malloc(sizeof(void *) * 10);
	v->path_img[0] = "./Sprites/wall.xpm";
	v->path_img[1] = "./Sprites/player_front.xpm";
	v->path_img[2] = "./Sprites/floor.xpm";
	v->path_img[3] = "./Sprites/coin.xpm";
	v->path_img[4] = "./Sprites/exit.xpm";
	v->path_img[5] = "./Sprites/player_back.xpm";
	v->path_img[6] = "./Sprites/player_right.xpm";
	v->path_img[7] = "./Sprites/player_left.xpm";
	v->path_img[8] = "./Sprites/enemy.xpm";
	v->path_img[9] = "./Sprites/exit2.xpm";
	v->m[0] = mlx_xpm_file_to_image(v->mx, v->path_img[0], &x, &y);
	v->m[1] = mlx_xpm_file_to_image(v->mx, v->path_img[1], &x, &y);
	v->m[2] = mlx_xpm_file_to_image(v->mx, v->path_img[2], &x, &y);
	v->m[3] = mlx_xpm_file_to_image(v->mx, v->path_img[3], &x, &y);
	v->m[4] = mlx_xpm_file_to_image(v->mx, v->path_img[4], &x, &y);
	v->m[5] = mlx_xpm_file_to_image(v->mx, v->path_img[5], &x, &y);
	v->m[6] = mlx_xpm_file_to_image(v->mx, v->path_img[6], &x, &y);
	v->m[7] = mlx_xpm_file_to_image(v->mx, v->path_img[7], &x, &y);
	v->m[8] = mlx_xpm_file_to_image(v->mx, v->path_img[8], &x, &y);
	v->m[9] = mlx_xpm_file_to_image(v->mx, v->path_img[9], &x, &y);
}

int	main(int argc, char **argv)
{
	t_vars	v;

	if (argc == 1)
		return (0);
	v.steps = 0;
	v.path = argv[1];
	read_map(&v);
	check_elements(&v);
	check_walls(&v);
	v.mx = mlx_init();
	load_img(&v);
	v.w = mlx_new_window(v.mx, v.x * 64, v.y * 64, "so_long");
	put_map(&v);
	mlx_hook(v.w, 17, 1L << 17, ft_close, &v);
	mlx_hook(v.w, 2, 1L << 0, keypress, &v);
	mlx_loop(v.mx);
}
