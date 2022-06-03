/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuszyns <cbuszyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:48:33 by cbuszyns          #+#    #+#             */
/*   Updated: 2022/06/03 15:55:52 by cbuszyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	you_won(t_vars *vars)
{
	ft_printf("You won!\n");
	ft_close(vars);
}

void	you_lost(t_vars *vars)
{
	ft_printf("You lost\n");
	ft_close(vars);
}

// int	enemy_animation(t_vars *vars)
// {
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[8], vars->e_x * 64, vars->e_y * 64);
// 	usleep(1000);
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], vars->e_x * 64, vars->e_y * 64);
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[9], vars->e_x * 64, vars->e_y * 64);
// 	return (0);
// }
