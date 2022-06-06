/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuszyns <cbuszyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:48:00 by cbuszyns          #+#    #+#             */
/*   Updated: 2022/06/06 13:22:39 by cbuszyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *v)
{
	if (v->mp[v->py - 1][v->px] == '1')
		return ;
	if (v->mp[v->py - 1][v->px] == 'H')
		you_lost(v);
	if (v->mp[v->py - 1][v->px] == 'E' && v->coin == 0)
		you_won(v);
	else if (v->mp[v->py - 1][v->px] == 'E' && v->coin > 0)
		return ;
	if (v->mp[v->py - 1][v->px] == 'C')
	{
		v->mp[v->py - 1][v->px] = '0';
		v->coin--;
	}
	if (v->coin == 0)
	{
		mlx_put_image_to_window(v->mx, v->w, v->m[2], v->e_x * 64, v->e_y * 64);
		mlx_put_image_to_window(v->mx, v->w, v->m[9], v->e_x * 64, v->e_y * 64);
	}
	mlx_put_image_to_window(v->mx, v->w, v->m[2], v->px * 64, v->py * 64);
	mlx_put_image_to_window(v->mx, v->w, v->m[2], v->px * 64, (v->py - 1) * 64);
	mlx_put_image_to_window(v->mx, v->w, v->m[5], v->px * 64, (v->py - 1) * 64);
	v->steps++;
	ft_printf("Steps: %d\n", v->steps);
	display_moves(v);
	v->py--;
}

void	move_down(t_vars *v)
{
	if (v->mp[v->py + 1][v->px] == '1')
		return ;
	if (v->mp[v->py + 1][v->px] == 'H')
		you_lost(v);
	if (v->mp[v->py + 1][v->px] == 'E' && v->coin == 0)
		you_won(v);
	else if (v->mp[v->py + 1][v->px] == 'E' && v->coin > 0)
		return ;
	if (v->mp[v->py + 1][v->px] == 'C')
	{
		v->mp[v->py + 1][v->px] = '0';
		v->coin--;
	}
	if (v->coin == 0)
	{
		mlx_put_image_to_window(v->mx, v->w, v->m[2], v->e_x * 64, v->e_y * 64);
		mlx_put_image_to_window(v->mx, v->w, v->m[9], v->e_x * 64, v->e_y * 64);
	}
	mlx_put_image_to_window(v->mx, v->w, v->m[2], v->px * 64, v->py * 64);
	mlx_put_image_to_window(v->mx, v->w, v->m[2], v->px * 64, (v->py + 1) * 64);
	mlx_put_image_to_window(v->mx, v->w, v->m[1], v->px * 64, (v->py + 1) * 64);
	v->steps++;
	ft_printf("Steps: %d\n", v->steps);
	display_moves(v);
	v->py++;
}

void	move_left(t_vars *v)
{
	if (v->mp[v->py][v->px - 1] == '1')
		return ;
	if (v->mp[v->py][v->px - 1] == 'H')
		you_lost(v);
	if (v->mp[v->py][v->px - 1] == 'E' && v->coin == 0)
		you_won(v);
	else if (v->mp[v->py][v->px - 1] == 'E' && v->coin > 0)
		return ;
	if (v->mp[v->py][v->px - 1] == 'C')
	{
		v->mp[v->py][v->px - 1] = '0';
		v->coin--;
	}
	if (v->coin == 0)
	{
		mlx_put_image_to_window(v->mx, v->w, v->m[2], v->e_x * 64, v->e_y * 64);
		mlx_put_image_to_window(v->mx, v->w, v->m[9], v->e_x * 64, v->e_y * 64);
	}
	mlx_put_image_to_window(v->mx, v->w, v->m[2], v->px * 64, v->py * 64);
	mlx_put_image_to_window(v->mx, v->w, v->m[2], (v->px - 1) * 64, v->py * 64);
	mlx_put_image_to_window(v->mx, v->w, v->m[7], (v->px - 1) * 64, v->py * 64);
	v->steps++;
	ft_printf("Steps: %d\n", v->steps);
	display_moves(v);
	v->px--;
}

void	move_right(t_vars *v)
{
	if (v->mp[v->py][v->px + 1] == '1')
		return ;
	if (v->mp[v->py][v->px + 1] == 'H')
		you_lost(v);
	if (v->mp[v->py][v->px + 1] == 'E' && v->coin == 0)
		you_won(v);
	else if (v->mp[v->py][v->px + 1] == 'E' && v->coin > 0)
		return ;
	if (v->mp[v->py][v->px + 1] == 'C')
	{
		v->mp[v->py][v->px + 1] = '0';
		v->coin--;
	}
	if (v->coin == 0)
	{
		mlx_put_image_to_window(v->mx, v->w, v->m[2], v->e_x * 64, v->e_y * 64);
		mlx_put_image_to_window(v->mx, v->w, v->m[9], v->e_x * 64, v->e_y * 64);
	}
	mlx_put_image_to_window(v->mx, v->w, v->m[2], v->px * 64, v->py * 64);
	mlx_put_image_to_window(v->mx, v->w, v->m[2], (v->px + 1) * 64, v->py * 64);
	mlx_put_image_to_window(v->mx, v->w, v->m[6], (v->px + 1) * 64, v->py * 64);
	v->steps++;
	ft_printf("Steps: %d\n", v->steps);
	display_moves(v);
	v->px++;
}
