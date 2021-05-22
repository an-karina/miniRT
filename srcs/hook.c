/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:59:14 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/22 22:22:00 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_struct.h"
#include "header_fill.h"
#include "scene.h"
#include <stdio.h>
int	key_hook(int keycode, t_mlx *mlx)
{
	int count;
	t_camera *camera;
	t_color	color;
	int x;
	int y;
	
	if (keycode == 48)
	{
		count = ft_lstsize(mlx->scene->cameras);
		if (mlx->current_cam < count)
		{
			mlx->current_cam++;
			mlx->scene->cameras = mlx->scene->cameras->next;
			printf("%d\n", mlx->current_cam);
		}
		else
		{
			mlx->scene->cameras = mlx->first_camera;
			mlx->current_cam = 1;
			printf("%d\n", mlx->current_cam);
		}
		x = 0;
		y = 0;
		camera = (t_camera *)mlx->scene->cameras->content;
		camera_base(camera, mlx->scene->resolution);
		while (y <  (mlx->scene)->resolution.height)
		{
			x = 0;
			while (x <  (mlx->scene)->resolution.width)
			{
				color = ray_trace(get_ray(x, y, *((t_camera *)(mlx->scene)->cameras->content), (mlx->scene)->resolution), *(mlx->scene));
				my_mlx_pixel_put(&mlx->img, x, y, rgb_to_int(color));
				x++;
			}
			y++;
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.img, 0, 0);
	return (0);
}