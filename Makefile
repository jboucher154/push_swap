# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 11:09:41 by jebouche          #+#    #+#              #
#    Updated: 2023/01/04 16:40:29 by jebouche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIB = libft/libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -I.

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

DEBUG = -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

%.o:%.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C libft

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re