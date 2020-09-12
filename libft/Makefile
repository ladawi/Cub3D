# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 09:29:31 by ladawi            #+#    #+#              #
#    Updated: 2020/09/12 18:05:12 by ladawi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC=ft_atoi.c\
ft_bzero.c\
ft_calloc.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_itoa.c\
ft_memccpy.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memmove.c\
ft_memset.c\
ft_memset.c\
ft_putchar_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_putstr_fd.c\
ft_split.c\
ft_strchr.c\
ft_strdup.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlcpy.c\
ft_strlen.c\
ft_strmapi.c\
ft_strncmp.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strtrim.c\
ft_substr.c\
ft_tolower.c\
ft_toupper.c\
ft_intlen.c\
get_next_line.c\
get_next_line_utils.c\
ft_intlenbase.c\
ft_strjoinfree.c\
ft_ultoax.c\
ft_findchar.c

LIST = $(addprefix src/,$(SRC))

SRCO = $(LIST:%.c= %.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\

BONUS_PATH = $(addprefix src/,$(BONUS))

BONUSO = $(BONUS_PATH:%.c= %.o)

INCLUDE = ./includes/libft.h ./includes/get_next_line.h

OBJ_DIR = obj

FLAGS = -Wall -Werror -Wextra

RED = \033[0;91m
YEL = \033[93m
END = \033[0m
GRE = \033[0;92m
PUR = \033[0;95m
BLU = \033[0;34m
BOLD = \033[1m


all: $(NAME)

$(NAME): $(SRCO) $(INCLUDE) $(OBJ_DIR)
	@ar -rcs $(NAME) $(SRCO)
	@echo "$(YEL)Made $(NAME)$(END)"

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@gcc $(FLAGS) -g -c $< -o $@
	@echo "$(GRE)$@$(END)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(BOLD)Removed *.o $(END)"

re: fclean all

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)$(BOLD)Removed $(NAME) $(END)"

bonus: $(NAME) $(BONUSO)
	@ar rc $(NAME) $(BONUSO)
