SRCS		= srcs/fill_evrthg.c srcs/get_ray.c srcs/main.c vector_math/vector_func_1.c\
				vector_math/vector_func_2.c vector_math/vector_func_3.c srcs/ray_trace.c\

INC			= libft/libft.h includes/camera.h includes/header_fill.h includes/header_struct.h includes/vector.h\
				includes/scene.h includes/solve_equation.h

OBJS		= $(SRCS:.c=.o)

CC			= gcc -g -O2
RM			= rm -f
CFLAGS		= -I includes/ -I mlx/
LIBS		= -L . -lmlx
MLX			= libmlx.dylib
NAME		= miniRT
LIBFT		= libft.a

all:		$(NAME)

$(NAME):	$(LIBFT) $(MLX) $(OBJS) $(INCS)
				@cp libft/$(LIBFT) .
				@cp mlx/$(MLX) .
				gcc -g libft.a ${CFLAGS} -o miniRT ${OBJS} ${LIBS}
				@echo "Done"

$(LIBFT):		
				@make -C libft

$(MLX):
				@make -C mlx 
clean:
			$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME) $(MLX) $(LIBFT)
				@make clean -C mlx
				@make clean -C libft

re:			fclean $(NAME)

.PHONY:			all clean fclean re
