SRCS =	srcs/end_pipex.c	srcs/execute_cmd.c	srcs/first_part.c 	srcs/last_part.c	srcs/middle_part.c \
		srcs/open_files.c	srcs/path.c	srcs/pipex.c

OBJS = ${SRCS:.c=.o}

INC = -I inc/ -I libft
LIBFTPATH = -L libft -lft
LIBS = ${INC} ${LIBFTPATH}

NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} 
		+$(MAKE) -C libft
		cc -o ${NAME} ${CFLAGS} ${OBJS} ${LIBS}

all:	${NAME}

clean:	
	@	+$(MAKE) -C libft clean
	@	rm -f ${OBJS} ${DEPS} ${OBJSBONUS} ${DEPSBONUS}

fclean:	clean;
	@	+$(MAKE) -C libft fclean
	@	@rm -f ${NAME} ${BONUS}

re:	fclean all
