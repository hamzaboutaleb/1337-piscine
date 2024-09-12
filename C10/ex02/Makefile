SRCS	= main.c
OBJS	= $(SRCS:.c=.o)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
NAME	= ft_tail

${NAME}:	${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

clean:
	${RM} ${OBJS}
fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re