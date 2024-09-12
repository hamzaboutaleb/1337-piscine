SRCS		= main.c io.c
OBJS		= $(SRCS:.c=.o)
NAME		= ft_cat
CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

${NAME}: $(OBJS)
			$(CC) ${CFLAGS} ${OBJS} -o ${NAME} 

all:		${NAME}

%.o:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

