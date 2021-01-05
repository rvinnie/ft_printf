SRSC	= main.c ft_printf.c ft_printf.h parser/parser.c handler/* \
		libft/libft.h libft/ft_strlen.c 

all: 
		gcc -Wall -Wextra -Werror ${SRSC}