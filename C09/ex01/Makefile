SRC			= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRCS		= ${addprefix ${PRE}, ${SRC}}
OBJS		= ${SRCS:.c=.o}
PRE			= ./srcs/
HEAD		= ./includes/
NAME		= libft.a
AR			= ar rc
RM			= rm -f
LIB			= ranlib
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}
			${LIB} ${NAME}

clean:
			$(RM) ${OBJS}

fclean:		clean
			$(RM) ${NAME}

re:			fclean all
.PHONY:		all clean fclean re
