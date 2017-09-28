# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carmand <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 21:43:02 by carmand           #+#    #+#              #
#    Updated: 2017/09/28 00:05:23 by carmand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c	

TMP = $(SRC:.c=.o)

LIB = libft/libft.a

CC = gcc -Wall -Wextra -Werror

.PHONY : all clean fclean re

all : $(NAME)

$(NAME): $(LIB) $(SRC)
	$(CC) $(FLAGS) -c $(SRC) -I . -I ./libft
	$(CC) $(FLAGS) $(TMP) -o $(NAME)  -L ./libft -lft -I . -I ./libft/

$(LIB):
	make -C libft

clean:
	rm -f $(TMP)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re : fclean all
