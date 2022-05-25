/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuszyns <cbuszyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:09:31 by cbuszyns          #+#    #+#             */
/*   Updated: 2022/05/25 15:57:45 by cbuszyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(void)
{
	ft_printf("INVALID MAP BOARDERS \n");
	exit(0);
}

void	check_elements(t_vars *vars)
{
	int i;
	int j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if(vars->map[i][j] != '1' && vars->map[i][j] != '0' && vars->map[i][j] != 'E' && vars->map[i][j] != 'P'
				&& vars->map[i][j] != 'C' && vars->map[i][j] != '\n' && vars->map[i][j] != '\0' && vars->map[i][j] != 'H')
			{
				ft_printf("Invalid character \n");
				exit(0);
			}
			if (vars->map[i][j] == 'P')
				vars->p_count++;
			if (vars->map[i][j] == 'E')
				vars->e_count++;
			if (vars->map[i][j] == 'C')
				vars->c_count++;
			j++;
		}
		i++;
	}
	if (vars->p_count < 1)
	{
		ft_printf("There is no player \n");
		exit(0);
	}
	if (vars->p_count > 1)
	{
		ft_printf("This isn't a multiplayer game \n");
		exit(0);
	}
	if (vars->c_count < 1)
	{
		ft_printf("There are no collectables \n");
		exit(0);
	}
	if(vars->e_count < 1)
	{
		ft_printf("There is no exit \n");
		exit(0);
	}
}

void	check_walls(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while(vars->map[y][x])
		{
			if (vars->map[0][x] != '1')
				map_error();
			else if (vars->map[y][0] != '1')
				map_error();
			else if (vars->map[y][vars->x - 1] != '1')
				map_error();
			else if (vars->map[vars->y - 1][x] != '1')
				map_error();
			x++;
		}
		y++;
	}
}
