SRC_NAME = ft_printf.c\
utlityprintf.c\
utlityprintf2.c

OBJ_NAME = $(SRC_NAME:.c=.o)
CFLAG = -Wall -Wextra -Werror
NAME = libftprintf.a
${NAME}:
	gcc -c $(CFLAG) $(SRC_NAME)
	ar -rc $(NAME) $(OBJ_NAME)

all: ${NAME}

bonus: ${NAME}

clean:
	rm -rf ${OBJ_NAME}
fclean: clean
	rm -f ${NAME}
re: fclean all
