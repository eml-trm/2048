# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 20:46:37 by etermeau          #+#    #+#              #
#    Updated: 2015/02/27 20:46:48 by etermeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048

LIB = libft/

HEADER = includes/

DIRSRC = srcs/

FLAGS = -Wall -Wextra -Werror

SRC = main.c \
	  ft_print_grid.c \
	  ft_tiles.c \
	  print_tab.c \
	  ft_move_right.c \
	  ft_move_left.c \
	  ft_move_up.c \
	  ft_move_down.c \
	  ft_score.c \
	  ft_init.c \
	  ft_key.c \
	  ft_menu.c


OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(LIB)
	@gcc $(FLAGS) -o $(NAME) $^ -L$(LIB) -lft -lcurses

%.o: $(DIRSRC)%.c
	@gcc $(FLAGS) -o $@ -c $< -I$(LIB)$(HEADER) -I$(HEADER)

clean:
	@rm -f $(OBJ)
	@make clean -s -C $(LIB)

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C $(LIB)

re: fclean all
