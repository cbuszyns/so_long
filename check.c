/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuszyns <cbuszyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:09:31 by cbuszyns          #+#    #+#             */
/*   Updated: 2022/06/06 14:41:01 by cbuszyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(void)
{
	ft_printf("INVALID MAP BOARDERS \n");
	exit(0);
}

void	element_utils(t_vars *v)
{
	if (v->p_count < 1)
	{
		ft_printf("There is no player \n");
		exit(0);
	}
	if (v->p_count > 1)
	{
		ft_printf("This isn't a multiplayer game \n");
		exit(0);
	}
	if (v->c_count < 1)
	{
		ft_printf("There are no collectables \n");
		exit(0);
	}
	if (v->e_count < 1)
	{
		ft_printf("There is no exit \n");
		exit(0);
	}
	return ;
}

void	check_elements(t_vars *v)
{
	int	i;
	int	j;

	i = -1;
	while (v->mp[++i])
	{
		j = -1;
		while (v->mp[i][++j])
		{
			if (v->mp[i][j] != '1' && v->mp[i][j] != '0' && v->mp[i][j] != 'E'
			&& v->mp[i][j] != 'P' && v->mp[i][j] != 'C' && v->mp[i][j] != '\n'
			&& v->mp[i][j] != '\0' && v->mp[i][j] != 'H')
			{
				ft_printf("Invalid character \n");
				exit(0);
			}
			if (v->mp[i][j] == 'P')
				v->p_count = 1;
			if (v->mp[i][j] == 'E')
				v->e_count += 1;
			if (v->mp[i][j] == 'C')
				v->c_count += 1;
		}		
	}
	element_utils(v);
}

void	check_walls(t_vars *v)
{
	int	x;
	int	y;

	y = 0;
	while (v->mp[y])
	{
		x = 0;
		while (v->mp[y][x])
		{
			if (v->mp[0][x] != '1')
				map_error();
			else if (v->mp[y][0] != '1')
				map_error();
			else if (v->mp[y][v->x - 1] != '1')
				map_error();
			else if (v->mp[v->y - 1][x] != '1')
				map_error();
			x++;
		}
		y++;
	}
}
