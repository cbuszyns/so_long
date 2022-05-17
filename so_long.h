/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuszyns <cbuszyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:00:12 by cbuszyns          #+#    #+#             */
/*   Updated: 2022/05/17 13:05:51 by cbuszyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include "./minilibx_mms_20200219/mlx.h"
# include <fcntl.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	void	*path;
	int		y;
	int		x;
	void	**img;
	void	**path_to_img;
	int		player_x;
	int		player_y;
	int		coin;
	int		steps;
}				t_vars;

void	read_map(t_vars *vars);
void	put_map(t_vars *vars);
int		keypress(int keycode, t_vars *vars);
void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
void	move_right(t_vars *vars);
void	move_left(t_vars *vars);
void	ft_close(t_vars *vars);


char	*ft_get_next_line(int fd);


#endif
