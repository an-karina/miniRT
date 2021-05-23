NAME	= libft.a
SRCDIR	= ./
OBJDIR	= ./
SRC		= ${SRCDIR}ft_bzero.c \
		  ${SRCDIR}ft_strlen.c \
		  ${SRCDIR}ft_strlcpy.c \
		  ${SRCDIR}ft_strlcat.c \
		  ${SRCDIR}ft_strchr.c \
		  ${SRCDIR}ft_strncmp.c \
		  ${SRCDIR}ft_atoi.c \
		  ${SRCDIR}ft_calloc.c \
		  ${SRCDIR}ft_strdup.c \
		  ${SRCDIR}ft_lstnew.c \
		  ${SRCDIR}ft_lstadd_front.c \
		  ${SRCDIR}get_next_line.c \
		  ${SRCDIR}ft_free_list.c \
		  ${SRCDIR}ft_lstsize.c

OBJ		= ${patsubst ${SRCDIR}%.c, ${OBJDIR}%.o, ${SRC}}
CC		= gcc -g
CFLAGS	= -Wall -Wextra -Werror

${OBJDIR}%.o: ${SRCDIR}%.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
	ar rc ${NAME} ${OBJ}
	ranlib ${NAME}

all:  ${NAME}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all
