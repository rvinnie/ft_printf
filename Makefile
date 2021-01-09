# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/08 14:47:02 by rvinnie           #+#    #+#              #
#    Updated: 2021/01/09 13:25:35 by rvinnie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-c -Wall -Wextra -Werror

NAME		=	libftprintf.a

SRCS		=	handler/handler.c \
				handler/c_handler.c \
				handler/digit_handler.c \
				handler/hex_handler.c \
				handler/s_handler.c \
				handler/ft_strlen.c \
				parser/parser.c \
				ft_printf.c

OBJS		=	$(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

all:	$(NAME)

clean:
	@$(RM) $(OBJS) ft_printf.h.gch

fclean:	clean
	@$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re 
