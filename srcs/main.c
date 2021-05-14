/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:23:51 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/14 20:23:10 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fill.h"
#include "light.h"
#include "solve_equation.h"
#include "../libft/libft.h"	
#include <stdio.h>
#include "parser.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int	check_name(char *str)
{
	int length;

	length = ft_strlen(str);
	return (ft_strncmp(str + length - 3, ".rt", 3));
}

// int	check_map_correct(t_scene *scene)
// {
// 	if (scene->resolution )
// }

int	main(int argc, char **argv)
{
	t_scene		*scene;
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_color 	color;
	int			x;
	int			y;

	if (argc > 3 || argc < 2 || check_name(argv[1]))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	scene = (t_scene *)malloc(sizeof(t_scene));
	scene->existance = DOES_NOT_EXIST;
	scene->resolution.existance = DOES_NOT_EXIST;
	scene->amb.existance = DOES_NOT_EXIST;
	scene->cameras = NULL;
	scene->light = NULL;
	scene->objects = NULL;
	parser(argv[1], scene);
	// if (check_map_correct(scene))
	// {
	// 	fill_scene_null(scene);
	// 	write(2, "Error\nMap is incorrect\n", 23);
	// 	return (-1);
	// }
	if (scene->existance == DOES_NOT_EXIST)
	{
		fill_scene_null(scene);
		write(2, "Error\n", 6);
		return (-1);
	}
	
	//printf("Sphere:\n center (%lf)\n", ((t_sphere *)(((t_object *)(scene->objects->content))->shape))->r);
	// printf("Camera:\n position (%lf, %lf, %lf)\n",((t_camera *)scene->cameras->content)->position.x,
	// ((t_camera *)scene->cameras->content)->position.y, ((t_camera *)scene->cameras->content)->position.z);
	// printf("Camera:\n position (%lf, %lf, %lf)\n",((t_camera *)scene->cameras->next->content)->position.x,
	// ((t_camera *)scene->cameras->next->content)->position.y, ((t_camera *)scene->cameras->next->content)->position.z);
	// printf("Light:\n center (%lf, %lf, %lf)\n",((t_light *)scene->light->content)->center.x,
	// ((t_light *)scene->light->content)->center.y, ((t_light *)scene->light->content)->center.z);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, scene->resolution.width, scene->resolution.height, "Karina's mini ray tracer");
    img.img = mlx_new_image(mlx,  scene->resolution.width,  scene->resolution.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	x = 0;
	y = 0;

	while (y <  scene->resolution.height)
	{
		x = 0;
		while (x <  scene->resolution.width)
		{
			color = ray_trace(get_ray(x, y, *((t_camera *)scene->cameras->content), scene->resolution), *scene);
			my_mlx_pixel_put(&img, x, y, rgb_to_int(color));
			//printf("x = %d | y = %d | color = %d\n", x, y, rgb_to_int(color));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
