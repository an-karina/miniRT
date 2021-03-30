/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:23:51 by jhleena           #+#    #+#             */
/*   Updated: 2021/03/30 20:51:56 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_struct.h"
#include "header_fill.h"
#include "vector.h"
#include "camera.h"
#include "scene.h"
#include "object.h"

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
	t_scene		scene;
	t_object	object;


	window = fill_wind(1500, 1000);
	point_of_view = fill_point(0, 0, 0);
	view = fill_vector(0, 0, 1);
	camera = fill_camera(point_of_view, view, (double)80, window);
	mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, window.width, window.height, "Hello world!");
    img.img = mlx_new_image(mlx,  window.width,  window.height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
	x = 0;
	y = 0;
	object.shape.center = fill_point(0, 0, 10);
	object.shape.r = 1;
	object.color.r = 0;
	object.color.g = 0;
	object.color.b = 255;
	scene.objects = object;
	scene.cameras = camera;
	while (y < window.height) 
	{
		x = 0;
		while (x < window.width)
		{
			color = ray_trace(get_ray(x, y, camera, window), scene);
			my_mlx_pixel_put(&img, x, y, color.b);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
