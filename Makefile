# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 11:09:41 by jebouche          #+#    #+#              #
#    Updated: 2023/01/03 18:33:48 by jebouche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIB = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

HOME_FLAGS = -g

DEPS = push_swap.h

SRCS = main.c \
		conquer.c \
		divide.c \
		lst_pop.c \
		push.c \
		read_inputs.c \
		reverse_rotate.c \
		rotate.c \
		sanitize_moves.c \
		sanitize_moves2.c \
		sort.c \
		swap.c \
		utility_one.c \
		utility_two.c \
		utility_three.c \
		utility_four.c \

OBJS = $(SRCS:.c=.o)

DEBUG = -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(HOME_FLAGS) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

%.o:%.c $(DEPS)
	$(CC) $(HOME_FLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(name)

re: fclean all

.PHONY: all clean fclean re