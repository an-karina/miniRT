/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:23:51 by jhleena           #+#    #+#             */
/*   Updated: 2021/04/08 17:18:22 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_struct.h"
#include "header_fill.h"
#include "vector.h"
#include "camera.h"
#include "scene.h"
#include "object.h"
#include "light.h"
#include "solve_equation.h"
#include "../libft/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int				main(void)
{
	t_camera	camera;
	t_vec		view;
	t_point		point_of_view;
	t_wind		window;
	void		*mlx;
    void		*mlx_win;
    t_data		img;
	t_color 	color;
	int			x;
	int			y;
	t_sphere	sphere;
	t_sphere	sphere_1;
	t_plane		plane;
	t_object	object;
	t_object	object_1;
	t_object	object_plane;
	t_scene		scene;
	t_ambient	ambient;
	t_light		light;

	window = fill_wind(700, 700);
	point_of_view = fill_point(0, 0, 0);
	view = fill_vector(0, 0, 1);
	camera = fill_camera(point_of_view, view, (double)90, window);
	mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, window.width, window.height, "Hello world!");
    img.img = mlx_new_image(mlx,  window.width,  window.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	x = 0;
	y = 0;

	ambient.intensity = 1;
	ambient.color.r = 255;
	ambient.color.g = 255;
	ambient.color.b = 255;
	scene.ambient = ambient;

	sphere.center = fill_point(0.0, 0.0, 10.0);
	sphere.r = 1;
	object.color.r = 100;
	object.color.g = 0;
	object.color.b = 0;
	object.shape = &sphere;
	object.intersection = &solve_equation_sphere;
	object.normal = &normal_sphere;
	scene.cameras = ft_lstnew(&camera);
	scene.objects =  ft_lstnew(&object);

	sphere_1.center = fill_point(0, 4.0, 7.0);
	sphere_1.r = 1;
	object_1.color.r = 150;
	object_1.color.g = 150;
	object_1.color.b = 150;
	object_1.shape = &(sphere_1);
	object_1.intersection = &solve_equation_sphere;
	object_1.normal = &normal_sphere;
	(scene.cameras)->next = ft_lstnew(&camera);
	(scene.objects)->next = ft_lstnew(&object_1);

	plane.p = fill_point(0.0, 0.0, 2.0);
	plane.norm = vec_norm(fill_vector(1.0,0.0, 0.0));
	object_plane.color.r = 150;
	object_plane.color.g = 150;
	object_plane.color.b = 255;
	object_plane.shape = &plane;
	object_plane.intersection = &solve_equation_plane;
	object_plane.normal = &normal_plane;
	(scene.cameras)->next->next = ft_lstnew(&camera);
	(scene.objects)->next->next = ft_lstnew(&object_plane);
	// (scene.cameras)->next = ft_lstnew(&camera);
	// (scene.objects)->next = ft_lstnew(&object_plane);

	light.center = fill_point(0.0, 0.0, 0.0);
	light.intensity = 0.8;
	light.color.r = 255;
	light.color.g = 255;
	light.color.b = 255;
	scene.light = ft_lstnew(&light);

	while (y < window.height)
	{
		x = 0;
		while (x < window.width)
		{
			color = ray_trace(get_ray(x, y, camera, window), scene);
				my_mlx_pixel_put(&img, x, y, rgb_to_int(color));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
