/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:23:51 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/23 01:09:03 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fill.h"
#include "light.h"
#include "solve_equation.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include <stdio.h>
#include "parser.h"

int	initialization_scene(t_mlx *mlx)
{
	mlx->scene = (t_scene *)malloc(sizeof(t_scene));
	if (!mlx->scene)
		return (0);
	mlx->scene->existance = DOES_NOT_EXIST;
	mlx->scene->resolution.existance = DOES_NOT_EXIST;
	mlx->scene->amb.existance = DOES_NOT_EXIST;
	mlx->scene->cameras = NULL;
	mlx->scene->light = NULL;
	mlx->scene->objects = NULL;
	return (1);
}

void	fill_mlx(t_mlx *mlx)
{
	mlx->first_camera = (mlx->scene)->cameras;
	mlx->current_cam = 1;
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, (mlx->scene)->resolution.width,
			(mlx->scene)->resolution.height, "Karina's mini ray tracer");
	mlx->img.img = mlx_new_image(mlx->mlx, (mlx->scene)->resolution.width,
			(mlx->scene)->resolution.height);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
}

void	draw_scene(t_mlx *mlx)
{
	t_color		color;
	t_camera	*camera;
	int			x;
	int			y;

	x = 0;
	y = 0;
	camera = (t_camera *)(mlx->scene)->cameras->content;
	camera_base(camera, (mlx->scene)->resolution);
	while (y < (mlx->scene)->resolution.height)
	{
		x = 0;
		while (x < (mlx->scene)->resolution.width)
		{
			color = ray_trace(get_ray(x, y, *camera, (mlx->scene)->resolution),
					*(mlx->scene));
			my_mlx_pixel_put(&mlx->img, x, y, rgb_to_int(color));
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;

	if (!check_input(argc, argv))
		return (-1);
	if (!initialization_scene(&mlx))
		return (-1);
	parser(argv[1], mlx.scene);
	if (check_map_correct(mlx.scene))
		fill_scene_null(mlx.scene);
	if (!check_scene_existance(&mlx))
		return (-1);
	fill_mlx(&mlx);
	draw_scene(&mlx);
	if (argc == 3)
	{
		bmp_file(mlx.img, (mlx.scene));
		return (0);
	}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img.img, 0, 0);
	my_mlx_key_hook(&mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
