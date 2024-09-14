SRCS	= main.c hex.c str.c str2.c utils.c
OBJS	= $(SRCS:.c=.o)
NAME	= ft_hexdump
CFLAGS	= -Wall -Wextra -Werror

${NAME}: ${OBJS}
	cc ${CFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

%.o : %.c
	cc ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}
fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re