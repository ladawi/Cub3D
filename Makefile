# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 09:29:31 by ladawi            #+#    #+#              #
#    Updated: 2020/09/08 17:25:53 by ladawi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D.out

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
	get_colors.c
	
SRCO = $(addprefix $(OBJ_DIR)/, $(SRC_LIST:%.c= %.o))

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_LIST))

LIBFT_O = $(LIBFT_SRC:%.c= %.o)

LIBFT = ./libft/libft.a

LIBFT_INCLUDE = ./libft/includes/libft.h\
	./libft/includes/get_next_line.h

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

$(NAME): $(OBJ_DIR) $(SRCO) $(INCLUDE) $(LIBFT)
	@echo "$(YEL)Made $(NAME)$(END)"
	@echo "$(PUR)Compiling$(END)"
	@gcc -fsanitize=address -o $(NAME) $(SRCO) $(LIBFT) -I ../MinilibX/includes/mlx.h -g MinilibX/libmlx_Linux.a -L ./minilibx -lX11 -lXext -lmlx -lm -lbsd -I libft/includes

mac : $(OBJ_DIR) $(SRCO) $(INCLUDE) $(LIBFT)
	@echo "$(YEL)Made $(NAME)$(END)"
	@echo "$(PUR)Compiling$(END)"
	# @gcc -fsanitize=address -I ../MinilibX/mlx.h -g -L ./MinilibX/. -framework OpenGL -framework AppKit -I includes -I libft/includes $(LIBFT) $(SRCO) -o $(NAME)
	@gcc -g -o $(NAME) $(SRCO) $(LIBFT) -I ../MinilibX/includes/mlx.h -g MinilibX/libmlx_Linux.a -L ./minilibx -lX11 -lXext -lmlx -lm -lbsd -I libft/includes

$(LIBFT) : $(LIBFT_INCLUDE)
	@make -C ./libft/

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc -g -c $< -I includes -I libft/includes -o $@
	@echo "$(GRE)$<$(END)"

clean:
	@make clean -C libft
	@echo "$(RED)$(BOLD)Made [clean] in libft$(END)"
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(BOLD)Removed *.o $(END)"

re: fclean all

fclean: clean
	@make fclean -C libft
	@echo "$(RED)$(BOLD)Made [fclean] in libft$(END)"
	@rm -rf $(NAME)
	@echo "$(RED)$(BOLD)Removed $(NAME) $(END)"
	@rm -rf Cub3d.out
	@rm -rf Cub3d.out.dSYM
	@rm -rf ./screenshot/Cub3d\ screen.bmp
	@echo "$(RED)$(BOLD)Removed *.out $(END)"

run : all 
	./Cub3d.out init.cub
##/* ne pas oublier de mettre les flags */##