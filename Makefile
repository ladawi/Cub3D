# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 09:29:31 by ladawi            #+#    #+#              #
#    Updated: 2020/09/18 14:21:22 by ladawi           ###   ########.fr        #
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
	spritesorting.c\
	engine.c\
	engine2.c\
	screenshot.c\
	get_colors.c\
	recursive.c

SRC_BONUS_LIST=\
	ft_drawcursor.c\
	ft_minimap.c

SRCO = $(addprefix $(OBJ_DIR)/, $(SRC_LIST:%.c= %.o))

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_LIST))

SRCO_BONUS = $(addprefix $(OBJ_BONUS_DIR)/, $(SRC_BONUS_LIST:%.c= %.o))

SRCS_BONUS = $(addprefix $(SRC_BONUS_DIR)/, $(SRC_BONUS_LIST))

LIBFT_O = $(LIBFT_SRC:%.c= %.o)

MINILIBX = ./minilibx-linux/libmlx.a

LIBFT = ./libft/libft.a

LIBFT_INCLUDE = ./libft/includes/libft.h\
	./libft/includes/get_next_line.h

MINILIBX_INCLUDE = ./minilibx-linux/mlx_int.h\
	./minilibx-linux/mlx.h

INCLUDE = includes/cub3d.h

SRC_DIR = src

SRC_BONUS_DIR = src_bonus

OBJ_DIR = obj

OBJ_BONUS_DIR = obj_bonus

FLAGS = -Wall -Werror -Wextra

END = \033[0m
RED = \033[0;91m
YEL = \033[93m
GRE = \033[0;92m
PUR = \033[0;95m
BLU = \033[0;34m
BOLD = \033[1m


all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ_BONUS_DIR) $(SRCO) $(SRCO_BONUS) $(INCLUDE) $(LIBFT) $(MINILIBX)
	@echo "$(YEL)Made $(NAME)$(END)"
	@echo "$(PUR)Compiling$(END)"
	@gcc $(FLAGS) -o $(NAME) $(SRCO) $(SRCO_BONUS) $(LIBFT) -I ../minilibx-linux/mlx.h -g minilibx-linux/libmlx_Linux.a -L ./minilibx -lX11 -lXext -lm -I libft/includes

bonus : $(NAME)

$(LIBFT) : $(LIBFT_INCLUDE)
	@make -C ./libft/

$(MINILIBX) :
	@make -S -C ./minilibx-linux >> /dev/null

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(OBJ_BONUS_DIR) :
	@mkdir $(OBJ_BONUS_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc $(FLAGS) -g -c $< -I includes -I libft/includes -o $@
	@echo "$(GRE)$@$(END)"

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@gcc $(FLAGS) -g -c $< -I includes -I libft/includes -o $@
	@echo "$(GRE)$@$(END)"

clean:
	@make clean -C libft
	@echo "$(RED)$(BOLD)Made [clean] in libft$(END)"
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_BONUS_DIR)
	@echo "$(RED)$(BOLD)Removed *.o $(END)"

re: fclean all

fclean: clean
	@make fclean -C libft
	@make clean -s -C minilibx-linux
	@echo "$(RED)$(BOLD)Made [fclean] in libft  & minilibx$(END)"
	@rm -rf $(NAME)
	@echo "$(RED)$(BOLD)Removed $(NAME) $(END)"
	@rm -rf ./screenshot/Cub3d_screen.bmp
	@echo "$(RED)$(BOLD)Removed ./screenshot/Cub3d_screen.bmp $(END)"

.PHONY : all clean fclean re