# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 21:43:02 by ttresori          #+#    #+#              #
#    Updated: 2017/10/04 02:24:01 by ttresori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_putchar.c ft_putstr.c ft_putnbr.c ft_strlen.c \
		ft_strcpy.c ft_strncpy.c ft_tolower.c ft_toupper.c \
		ft_isprint.c ft_isascii.c ft_isalpha.c 	ft_isalnum.c \
		ft_isdigit.c ft_strcmp.c ft_strncmp.c ft_strstr.c \
		ft_strnstr.c ft_strchr.c ft_strrchr.c ft_strcat.c \
		ft_strncat.c ft_bzero.c ft_memccpy.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_atoi.c ft_memalloc.c ft_memdel.c ft_strnew.c \
		ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
		ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
		ft_itoa.c ft_strlcat.c ft_putendl.c ft_putchar_fd.c \
		ft_putstr_fd.c	ft_putendl_fd.c ft_putnbr_fd.c ft_strdup.c \
		ft_free_char_2d.c ft_free_char_3d.c ft_free_int_2d.c \
		ft_free_int_3d.c ft_swap_char.c ft_strndup.c ft_puttab.c \
		ft_putntab.c ft_putnbrtab.c ft_startstop.c ft_isupper.c \
		ft_putnbrspace.c ft_islower.c ft_lstadd.c ft_lstdel.c ft_lstmap.c \
		ft_lstnew.c ft_lstiter.c ft_lstdelone.c ft_putstrspace.c \
		ft_putstrstart.c ft_print_space.c get_next_line.c \
		ft_strsdup.c ft_realloc.c ft_strjoincl.c ft_strjoinchcl.c \
		ft_strjoinchcl.c ft_strjoinca.c ft_startcpy.c ft_strjoinch.c \
		ft_char_2d.c

OBJ = $(SRC:.c=.o)

LIB = libft.h

CC = gcc -Wall -Werror -Wextra

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) :
	$(CC) -c $(SRC) -I .
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
