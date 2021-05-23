/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:59:14 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/23 11:28:59 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_struct.h"
#include "header_fill.h"
#include "scene.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int	my_exit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	int count;
	t_camera *camera;
	t_color	color;
	int x;
	int y;

	if (keycode == 48)
	{
		count = ft_lstsize(mlx->first_camera);
		if (mlx->current_cam <= count)
		{
			mlx->current_cam++;
			mlx->scene->cameras = mlx->scene->cameras->next;
		}
		else
		{
			mlx->scene->cameras = mlx->first_camera;
			mlx->current_cam = 1;
		}
		x = 0;
		y = 0;
		camera = (t_camera *)mlx->scene->cameras->content;
		draw_scene(mlx);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.img, 0, 0);
	return (0);
}

void	my_mlx_key_hook(t_mlx *mlx)
{
	mlx_key_hook(mlx->mlx_win, key_hook,mlx);
	mlx_hook(mlx->mlx_win, 17, 0, my_exit, mlx);
}
