/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:23:51 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/09 15:05:35 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fill.h"
#include "light.h"
#include "solve_equation.h"
#include "../libft/libft.h"	
#include <stdio.h>
#include "parser.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int		check_name(char *str)
{
	int length;

	length = ft_strlen(str);
	return (ft_strncmp(str + length - 3, ".rt", 3));
}

int				main(int argc, char **argv)
{
	// t_camera	camera;
	// t_vec		view;
	// t_point		point_of_view;
	// t_wind		window;
	// void		*mlx;
    // void		*mlx_win;
    // t_data		img;
	// t_color 	color;
	// int			x;
	// int			y;
	// t_sphere	sphere;
	// t_sphere	sphere_1;
	// t_plane		plane;
	// t_object	object;
	// t_object	object_1;
	// t_object	object_plane;
	t_scene		scene;
	// t_ambient	ambient;
	// t_light		light;
	// t_light		light_2;
	int			fd;

	if (argc > 3 || argc < 2 || check_name(argv[1]))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	// scene.resolution.existance = DOES_NOT_EXIST;
	// scene.existance = DOES_NOT_EXIST;
	// scene.amb.existance = DOES_NOT_EXIST;
	scene = fill_scene_null(scene);
	//printf("%s\n", argv[1]);
	scene = parser(argv[1]);
	//printf("%d | %d", scene.resolution.height, scene.resolution.width);
	if (scene.existance == DOES_NOT_EXIST)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	// window = fill_wind(950, 950);
	// point_of_view = fill_point(0, 0, 0);
	// view = fill_vector(0, 0, 1);
	// camera = fill_camera(point_of_view, view, (double)90, window);
	// mlx = mlx_init();
    // mlx_win = mlx_new_window(mlx, window.width, window.height, "Hello world!");
    // img.img = mlx_new_image(mlx,  window.width,  window.height);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	// x = 0;
	// y = 0;

	// ambient.intensity = 0.2;
	// ambient.color = (t_color){255, 255, 255};
	// scene.amb = ambient;

	// sphere.center = fill_point(-5.0, 0.0, 10.0);
	// sphere.r = 1;
	// object.color = (t_color){170, 0, 0};
	// object.shape = &sphere;
	// object.intersection = &solve_equation_sphere;
	// object.norm = &normal_sphere;
	// scene.cameras = ft_lstnew(&camera);
	// scene.objects =  ft_lstnew(&object);

	// sphere_1.center = fill_point(0.0, 0.0, 10.0);
	// sphere_1.r = 1;
	// object_1.color = (t_color){150, 150, 150};
	// object_1.shape = &(sphere_1);
	// object_1.intersection = &solve_equation_sphere;
	// object_1.norm = &normal_sphere;
	// (scene.cameras)->next = ft_lstnew(&camera);
	// (scene.objects)->next = ft_lstnew(&object_1);

	// plane.p = fill_point(1.0, 0.0, 0.0);
	// plane.norm = vec_norm(fill_vector(1.0,0.0, 0.0));
	// object_plane.color = (t_color){150, 150, 255};
	// object_plane.shape = &plane;
	// object_plane.intersection = &solve_equation_plane;
	// object_plane.norm = &normal_plane;
	// (scene.cameras)->next->next = ft_lstnew(&camera);
	// (scene.objects)->next->next = ft_lstnew(&object_plane);

	// // light.center = fill_point(0.0, 0.0, 0.0);
	// // light.intensity = 0.4;
	// // light.color = (t_color){255, 255, 255};
	// // scene.light = ft_lstnew(&light);

	// light_2.center = fill_point(-11.0, 0.0, 9.0);
	// light_2.intensity = 0.8;
	// light_2.color = (t_color){255, 0, 255};
	// // scene.light->next = ft_lstnew(&light_2);
	// scene.light = ft_lstnew(&light_2);

	// while (y < window.height)
	// {
	// 	x = 0;
	// 	while (x < window.width)
	// 	{
	// 		color = ray_trace(get_ray(x, y, camera, window), scene);
	// 		my_mlx_pixel_put(&img, x, y, rgb_to_int(color));
	// 		//printf("x = %d | y = %d | color = %d\n", x, y, rgb_to_int(color));
	// 		x++;
	// 	}
	// 	y++;
	// }
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
	return (0);
}
