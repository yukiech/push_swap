# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 09:31:22 by ahuber            #+#    #+#              #
#    Updated: 2022/01/06 16:38:40 by ahuber           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	push_swap.c \
		input_check.c \
		algo_small.c \
		array_handle.c \
		array_handle2.c \
		array_handle3.c \
		algo.c \
		ft_minilibft.c \
		ft_split_shit.c \
		too_long.c \
		algo_simple.c \
		replace_double.c

OBJ = $(SRC:.c=.o)

CC      = gcc
RM      = rm -f

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): ${OBJ}
	$(CC) -g -o $(NAME) ${OBJ}

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re:		fclean all
