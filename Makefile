# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 09:29:31 by ladawi            #+#    #+#              #
#    Updated: 2020/09/12 16:33:34 by ladawi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

SRC_LIST=\
	main.c\
	initgame.c\
	parsing.c\
	getresolution.c\
	initdata.c\
	get_textures.c\
	fncts.c\
	fncts2.c\
	event.c\
	game.c\
	window.c\
	sprite.c\
	player.c\
	ft_minimap.c\
	spritesorting.c\
	ft_drawcursor.c\
	engine.c\
	engine2.c\
	screenshot.c\
	get_colors.c\
	recursive.c
	
SRCO = $(addprefix $(OBJ_DIR)/, $(SRC_LIST:%.c= %.o))

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_LIST))

LIBFT_O = $(LIBFT_SRC:%.c= %.o)

MINILIBX = ./minilibx-linux/libmlx.a

LIBFT = ./libft/libft.a

LIBFT_INCLUDE = ./libft/includes/libft.h\
	./libft/includes/get_next_line.h

MINILIBX_INCLUDE = ./minilibx-linux/mlx_int.h\
	./minilibx-linux/mlx.h

INCLUDE = includes/cub3d.h

SRC_DIR = src

OBJ_DIR = obj

FLAGS = -Wall -Werror -Wextra

END = \033[0m
RED = \033[0;91m
YEL = \033[93m
GRE = \033[0;92m
PUR = \033[0;95m
BLU = \033[0;34m
BOLD = \033[1m


all: $(NAME)

$(NAME): $(OBJ_DIR) $(SRCO) $(INCLUDE) $(LIBFT) $(MINILIBX)
	@echo "$(YEL)Made $(NAME)$(END)"
	@echo "$(PUR)Compiling$(END)"
	@gcc -fsanitize=address $(FLAGS) -o $(NAME) $(SRCO) $(LIBFT) -I ../minilibx-linux/mlx.h -g minilibx-linux/libmlx_Linux.a -L ./minilibx -lX11 -lXext -lm -I libft/includes

$(LIBFT) : $(LIBFT_INCLUDE)
	@make -C ./libft/

$(MINILIBX) :
	@make --silent -C ./minilibx-linux

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc $(FLAGS) -g -c $< -I includes -I libft/includes -o $@
	@echo "$(GRE)$<$(END)"

clean:
	@make clean -C libft
	@echo "$(RED)$(BOLD)Made [clean] in libft$(END)"
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(BOLD)Removed *.o $(END)"

re: fclean all

fclean: clean
	@make fclean -C libft
	@make clean -s -C minilibx-linux
	@echo "$(RED)$(BOLD)Made [fclean] in libft  & minilibx$(END)"
	@rm -rf $(NAME)
	@echo "$(RED)$(BOLD)Removed $(NAME) $(END)"
	@rm -rf Cub3D
	@rm -rf ./screenshot/Cub3d\ screen.bmp
	@echo "$(RED)$(BOLD)Removed Cub3D $(END)"

.PHONY : all clean fclean re