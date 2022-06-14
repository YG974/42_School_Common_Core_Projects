# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygeslin <ygeslin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/11 17:31:19 by ygeslin           #+#    #+#              #
#    Updated: 2022/06/14 13:56:04 by ygeslin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Cub3D

SRC_MLX	= ./minilibx
SRC_LIBFT	= ./libft

SRC 		=	src/cub \
					src/parse \
					src/parse_map \
					src/wall_1 \
					src/wall_2 \
					src/sprite_1 \
					src/sprite_2 \
					src/move \
					src/key \
					src/utils \
					src/bitmap \
					src/utils_2 \


FILES = $(addsuffix .c, $(SRC))

LIBFT = $(SRC_LIBFT)/libft.a

OBJ = $(FILES:.c=.o)

CC			= clang

LIB_FLAGS	= -lmlx -framework OpenGL -framework AppKit

FLAGS		= -O3 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(SRC_LIBFT) && make clean -C $(SRC_LIBFT)
	make -C $(SRC_MLX)
	$(CC) -o $(NAME) $(LIBFT) -L $(SRC_MLX) $(LIB_FLAGS) $(OBJ) $(FLAGS) -g


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME) "map.cub"

save: $(NAME)
	./$(NAME) "map.cub" "--save"

leaks: $(NAME)
	./Cub3D map.cub &>/dev/null & disown && sleep 1 && leaks Cub3D

.PHONY:            all clean fclean re test save leaks
