# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ml <ml@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 09:59:07 by ml                #+#    #+#              #
#    Updated: 2023/03/13 10:47:00 by ml               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

cc = cc

CFLAGS = -Wall -Werror -Wextra -g3

PATH_SRC = src

PATH_LIB = libft

SRC = $(PATH_SRC)/ft_parsing.c\
	  $(PATH_SRC)/moves/ft_push.c\
	  $(PATH_SRC)/ft_moves_gestion.c\
	  $(PATH_SRC)/ft_create_gestion.c\
	  $(PATH_SRC)/moves/ft_swap.c\
	  $(PATH_SRC)/moves/ft_rotate.c\
	  $(PATH_SRC)/moves/ft_reverse_rotate.c\
	  $(PATH_SRC)/ft_utils.c\
	  $(PATH_SRC)/main.c\

LIB = $(PATH_LIB)/libft.a

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(LIB) $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo "\n Compilation OK\n"

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB) :
	@make -s -C $(PATH_LIB)

clean :
	make -C $(PATH_LIB) clean
	rm -f $(OBJ)

fclean : clean
	make -C $(PATH_LIB) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
