SRCS		= srcs/fill_evrthg.c srcs/get_ray.c srcs/main.c vector_math/vector_func_1.c\
				vector_math/vector_func_2.c vector_math/vector_func_3.c\

INC			= includes/camera.h includes/header_fill.h includes/header_struct.h includes/vector.h

OBJS		= $(SRCS:.c=.o)

CC			= gcc -O2
RM			= rm -f
CFLAGS		= -I includes/ -I mlx/
LIBS		= -L . -lmlx
MLX			= libmlx.dylib
NAME		= miniRT

all:		$(NAME)

$(NAME):	$(MLX) $(OBJS) $(INCS)
				@cp mlx/$(MLX) .
				gcc -g ${CFLAGS} -o miniRT ${OBJS} ${LIBS}
				@echo "Done"

$(MLX):
				@make -C mlx

clean:
			$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME) $(MLX)
				@make clean -C mlx

re:			fclean $(NAME)

.PHONY:			all clean fclean re
