/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuszyns <cbuszyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:48:33 by cbuszyns          #+#    #+#             */
/*   Updated: 2022/06/06 13:01:49 by cbuszyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	you_won(t_vars *v)
{
	ft_printf("You won!\n");
	ft_close(v);
}

void	you_lost(t_vars *v)
{
	ft_printf("You lost\n");
	ft_close(v);
}
