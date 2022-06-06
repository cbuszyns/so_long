/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuszyns <cbuszyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:00:12 by cbuszyns          #+#    #+#             */
/*   Updated: 2022/06/06 13:36:35 by cbuszyns         ###   ########.fr       */
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
	void	*mx;
	void	*w;
	char	**mp;
	void	*path;
	int		y;
	int		x;
	void	**m;
	char	**path_img;
	int		px;
	int		py;
	int		coin;
	int		steps;
	int		p_count;
	int		e_count;
	int		c_count;
	int		e_x;
	int		e_y;
}				t_vars;

void	read_map(t_vars *vars);
void	put_map(t_vars *vars);
int		keypress(int keycode, t_vars *vars);
void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
void	move_right(t_vars *vars);
void	move_left(t_vars *vars);
int		ft_close(t_vars *vars);
void	check_elements(t_vars *vars);
void	check_walls(t_vars *vars);
void	you_won();
void	you_lost();
void	display_moves(t_vars *vars);


char	*ft_get_next_line(int fd);


#endif
