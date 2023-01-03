# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 11:09:41 by jebouche          #+#    #+#              #
#    Updated: 2022/12/28 17:01:11 by jebouche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIB = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

HOME_FLAGS = -g

DEPS = push_swap.h

SRCS = push_swap.c sort.c sorting_utility.c lst_utility.c lst_pop.c \
		check_if_sorted.c conquer.c push.c read_inputs.c reverse_rotate.c \
		rotate.c swap.c

OBJS = $(SRCS:.c=.o)

DEBUG = -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(HOME_FLAGS) -o $(NAME) $(OBJS) $(LIB)

%.o:%.c $(DEPS)
	$(CC) $(HOME_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(name)

re: fclean all

.PHONY: all clean fclean re