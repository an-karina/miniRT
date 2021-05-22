SRCS		= srcs/fill_evrthg.c srcs/get_ray.c srcs/main.c vector_math/vector_func_1.c\
				vector_math/vector_func_2.c vector_math/vector_func_3.c srcs/ray_trace.c\
				srcs/r_g_b.c srcs/light.c srcs/normals.c parser/parser.c parser/parse_resolution.c\
				parser/parse_ambient.c parser/parse_camera.c parser/parse_light.c parser/sphere.c\
				parser/plane.c parser/square.c parser/cylinder.c parser/triangle.c srcs/solve_equation.c\
				srcs/bmp_file.c srcs/hook.c

INC			= includes/camera.h includes/header_fill.h includes/header_struct.h includes/vector.h\
				includes/scene.h includes/solve_equation.h includes/light.h includes/parser.h 

OBJS		= $(SRCS:.c=.o)

CC			= gcc -g -O2
RM			= rm -f
CFLAGS		= -I includes/ -I mlx/
LIBS		= -L . -lmlx libft.a
MLX			= libmlx.a
NAME		= miniRT
LIBFT		= libft.a

all:		$(NAME)

$(NAME):	$(LIBFT) $(MLX) $(OBJS) $(INCS)
				@cp libft/$(LIBFT) .
				@cp mlx/$(MLX) .
				gcc -g -framework AppKit -framework OpenGL  ${CFLAGS}  ${OBJS} ${LIBS} ${MLX} -o miniRT
				@echo "Done"

$(LIBFT):		
				@make -C libft

$(MLX):
				@make -C mlx 

clean:
				$(RM) $(OBJS)

fclean:
				$(RM) $(NAME) $(MLX) $(LIBFT)
				@make clean -C mlx
				@make clean -C libft

re:			fclean $(NAME)

.PHONY:			all clean fclean re
