# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchindri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/07 12:55:24 by mchindri          #+#    #+#              #
#    Updated: 2016/03/18 10:43:18 by mchindri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c ft_expose.c mlx_put_pixel_to_image.c ft_colors.c 
OFILES = $(SRC:.c=.o)


FLAGS = 

FLAG = -Wall -Wextra -Werror
MAIN = main.c
NAME = fractol
INCLUDES = -I . -I libft/includes

LIB = .libft
MLX = .libmlx

$(NAME): $(LIB) $(MLX)
		@gcc -c $(FLAGS) $(INCLUDES) $(SRC)
		@gcc -o $(NAME) $(OFILES) -L minilibx_macos -lmlx -framework \
			OpenGL -framework AppKit -L libft -lft

$(LIB):
		@make -C libft/ re
		@touch $(LIB)

$(MLX):
		@make -C minilibx_macos re
		@touch $(MLX)
clean:
		@rm -f $(OFILES)
		@rm -f $(NAME)
fclean: clean
		@make -C libft fclean
		@rm -f $(LIB)
		@make -C minilibx_macos clean
		@rm -f $(MLX)
all: mlx lib $(NAME)

re: clean $(NAME)

test: re
	./test.sh $(NAME)

