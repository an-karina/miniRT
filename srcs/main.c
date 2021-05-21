/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:23:51 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/20 15:28:21 by jhleena          ###   ########.fr       */
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

int	check_map_correct(t_scene *scene)
{
	if (scene->resolution.existance != EXISTS)
		return (1);
	if (scene->amb.existance != EXISTS)
		return (1);
	if (scene->cameras == NULL)
		return (1);
	if (scene->objects == NULL)
		return (1);
	return (0);
}

int		is_screen(char *str, char *bmp)
{
	while (*str)
	{
		if (*str != *bmp)
			return (1);
		str++;
		bmp++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_scene		*scene;
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_color 	color;
	int			x;
	int			y;

	if (argc > 3 || argc < 2 || check_name(argv[1]) || (argc == 3 && is_screen(argv[2], "--save")))
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
	if (check_map_correct(scene))
		fill_scene_null(scene);
	if (scene->existance == DOES_NOT_EXIST)
	{
		fill_scene_null(scene);
		write(2, "Error\n", 6);
		return (-1);
	}
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, scene->resolution.width, scene->resolution.height, "Karina's mini ray tracer");
    img.img = mlx_new_image(mlx,  scene->resolution.width,  scene->resolution.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	x = 0;
	y = 0;
	
	camera_base((t_camera *)scene->cameras->content, scene->resolution);
	while (y <  scene->resolution.height)
	{
		x = 0;
		while (x <  scene->resolution.width)
		{
			color = ray_trace(get_ray(x, y, *((t_camera *)scene->cameras->content), scene->resolution), *scene);
			my_mlx_pixel_put(&img, x, y, rgb_to_int(color));
			x++;
		}
		y++;
	}
	if (argc == 3 && is_screen(argv[2], "--save"))
		bmp_file(img, scene);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
