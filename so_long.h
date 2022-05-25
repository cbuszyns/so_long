/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuszyns <cbuszyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:00:12 by cbuszyns          #+#    #+#             */
/*   Updated: 2022/05/25 15:10:51 by cbuszyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>
# include "./mlx/mlx.h"
# include <fcntl.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	void	*path;
	int		y;
	int		x;
	void	**img;
	char	**path_to_img;
	int		player_x;
	int		player_y;
	int		coin;
	int		steps;
	int		p_count;
	int		e_count;
	int		c_count;
}				t_vars;

void	read_map(t_vars *vars);
void	put_map(t_vars *vars);
int		keypress(int keycode, t_vars *vars);
void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
void	move_right(t_vars *vars);
void	move_left(t_vars *vars);
void	ft_close(t_vars *vars);
void	check_elements(t_vars *vars);
void	check_walls(t_vars *vars);


char	*ft_get_next_line(int fd);


#endif
