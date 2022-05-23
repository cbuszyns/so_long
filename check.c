/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuszyns <cbuszyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:09:31 by cbuszyns          #+#    #+#             */
/*   Updated: 2022/05/23 15:44:12 by cbuszyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    invalid_char(t_vars *vars)
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
                && vars->map[i][j] != 'C' && vars->map[i][j] != '\n' && vars->map[i][j] != '\0')
            {
                ft_printf("Invalid map \n");
                exit(0);
            }
            j++;
        }
        i++;
    }
}