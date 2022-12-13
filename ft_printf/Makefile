# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 16:53:06 by jebouche          #+#    #+#              #
#    Updated: 2022/12/13 11:44:53 by jebouche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB = libft.a

SRCS =  ft_printf.c conversion.c flags.c handle_specifiers.c legend.c \
		characters.c hexadecimal.c itoa_base.c numbers.c padding.c \
		percent.c unsigned.c num_utils.c

OBJS =  ft_printf.o conversion.o flags.o handle_specifiers.o legend.o \
		characters.o hexadecimal.o itoa_base.o numbers.o padding.o \
		percent.o unsigned.o num_utils.o

DEPS = -Ift_printf.h

CC = cc

CFLAGS = -Wall -Werror -Wextra $(DEPS) -g

all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) -C libft	
		cp ./libft/$(LIB) ./$(NAME)
		ar -rucs $(NAME) $(OBJS)

%.o: %.c $(DEPS)
		$(CC) $(CFLAGS) -c $< -o $@
		
clean:
		rm -f $(OBJS) $(B_OBJS)
		$(MAKE) fclean -C libft

fclean: clean
		rm -f $(NAME)

re: fclean all

bonus: $(NAME)


.PHONY: all clean fclean re