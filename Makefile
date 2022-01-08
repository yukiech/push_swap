# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 09:31:22 by ahuber            #+#    #+#              #
#    Updated: 2022/01/08 09:13:49 by ahuber           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

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

SRC_BONUS =	checker2.c \
		checker.c \
		input_check.c \
		algo_small.c \
		array_handle.c \
		array_handle2.c \
		array_handle3.c \
		algo.c \
		ft_minilibft.c \
		ft_minilibft2.c \
		ft_split_shit.c \
		too_long.c \
		algo_simple.c \
		replace_double.c \
		get_next_line.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC      = gcc
RM      = rm -f

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

bonus:	$(BONUS)

$(NAME): ${OBJ}
	$(CC) $(CFLAGS) -g -o $(NAME) ${OBJ}

$(BONUS): ${OBJ_BONUS}
	$(CC) $(CFLAGS) ${OBJ_BONUS} -o $(NAME_BONUS)

clean:
		${RM} ${OBJ}
		${RM} ${OBJ_BONUS}

fclean: clean
		${RM} ${NAME}
		${RM} ${NAME_BONUS}

re:		fclean all

.PHONY: all bonus clean fclean re
