/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:23:51 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/22 22:59:35 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fill.h"
#include "light.h"
#include "solve_equation.h"
#include "../libft/libft.h"	
#include "../mlx/mlx.h"
#include <stdio.h>
#include "parser.h"

int	key_hook(int keycode, t_mlx *mlx);

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

int	my_exit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

void	my_mlx_key_hook(t_mlx mlx)
{
	mlx_key_hook(mlx.mlx_win, key_hook,&mlx);
	mlx_hook(mlx.mlx_win, 17, 0, my_exit, &mlx);
}

int	main(int argc, char **argv)
{
	//t_scene		*scene;
	t_mlx		mlx;
	//t_data		img;
	t_color 	color;
	int			x;
	int			y;

	if (argc > 3 || argc < 2 || check_name(argv[1]) || (argc == 3 && is_screen(argv[2], "--save")))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	
	mlx.scene = (t_scene *)malloc(sizeof(t_scene));
	(mlx.scene)->existance = DOES_NOT_EXIST;
	(mlx.scene)->resolution.existance = DOES_NOT_EXIST;
	(mlx.scene)->amb.existance = DOES_NOT_EXIST;
	(mlx.scene)->cameras = NULL;
	(mlx.scene)->light = NULL;
	(mlx.scene)->objects = NULL;
	parser(argv[1], mlx.scene);
	mlx.first_camera = (mlx.scene)->cameras;
	mlx.current_cam = 1;
	if (check_map_correct(mlx.scene))
		fill_scene_null(mlx.scene);
	if ((mlx.scene)->existance == DOES_NOT_EXIST)
	{
		fill_scene_null(mlx.scene);
		write(2, "Error\n", 6);
		return (-1);
	}
	
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, (mlx.scene)->resolution.width, (mlx.scene)->resolution.height, "Karina's mini ray tracer");
    mlx.img.img = mlx_new_image(mlx.mlx,  (mlx.scene)->resolution.width,  (mlx.scene)->resolution.height);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length,
								&mlx.img.endian);
	x = 0;
	y = 0;
	
	camera_base((t_camera *)(mlx.scene)->cameras->content, (mlx.scene)->resolution);
	while (y <  (mlx.scene)->resolution.height)
	{
		x = 0;
		while (x <  (mlx.scene)->resolution.width)
		{
			color = ray_trace(get_ray(x, y, *((t_camera *)(mlx.scene)->cameras->content), (mlx.scene)->resolution), *(mlx.scene));
			my_mlx_pixel_put(&mlx.img, x, y, rgb_to_int(color));
			x++;
		}
		y++;
	}
	if (argc == 3 && !is_screen(argv[2], "--save"))
	{
		bmp_file(mlx.img, (mlx.scene));
		return (0);
	}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img.img, 0, 0);
	my_mlx_key_hook(mlx);
	mlx_loop(mlx.mlx);
	//fill_scene_null(mlx.scene);
	return (0);
}
