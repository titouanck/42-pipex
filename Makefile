SRCS =	${wildcard srcs/*.c}

OBJS = ${SRCS:.c=.o}

INC = -I inc/ -I libft
LIBFTPATH = -L libft -lft
LIBS = ${INC} ${LIBFTPATH}

# NUMBERS = 3 1 2 4

NAME = pipex
CC = cc
CFLAGS =# -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} 
		+$(MAKE) -C libft
		cc -o ${NAME} ${CFLAGS} ${OBJS} ${LIBS}

all:	${NAME}

clean:	
#	@	+$(MAKE) -C libft clean
	@	rm -f ${OBJS} ${DEPS} ${OBJSBONUS} ${DEPSBONUS}

fclean:	clean;
	@	+$(MAKE) -C libft fclean
	@	@rm -f ${NAME} ${BONUS}

re:	fclean all

# My rules

norminette:
		clear
		norminette srcs/
		norminette inc/
		norminette libft/
