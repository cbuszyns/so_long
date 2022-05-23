# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbuszyns <cbuszyns@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:57:20 by fdrudi            #+#    #+#              #
#    Updated: 2022/05/23 15:37:08 by cbuszyns         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRC			=	so_long.c map.c get_next_line.c \
				movement.c check.c\

OBJ			=	$(SRC:.c=.o)

MLX			=	./libmlx.dylib

LIBFT		=	Libft/libft.a

FT_PRINTF	=	ft_printf/libftprintf.a

CC			=	gcc #-fsanitize=address

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

%.o:%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			make -C ./libft
			make -C ./mlx
			make -C ./ft_printf
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(LIBFT) $(FT_PRINTF)

all:		$(NAME)

clean:
			${RM} $(OBJ)

fclean: 	clean
			${RM} $(NAME) ${OBJ}

fclean.all:	fclean
			make fclean -C libft
			make clean -C mlx
			make fclean -C ft_printf

re:			fclean all

re.all:		fclean.all all

.PHONY:		all clean fclean re
