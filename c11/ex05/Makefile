SRCS	= main.c io.c op.c
OBJS	= $(SRCS:.c=.o)
NAME	= do-op
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
