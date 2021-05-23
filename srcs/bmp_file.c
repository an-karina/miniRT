/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:07:12 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/23 15:58:30 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_struct.h"
#include "scene.h"

int	image_pixel_color(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	write_bmp(int fd, t_scene *scene)
{
	int	size;
	int	pl;
	int	deep_cl;
	int	compression;
	int	image_size;

	size = 54 + 4 * scene->resolution.width * scene->resolution.height;
	pl = 1;
	deep_cl = 32;
	compression = 0;
	image_size = scene->resolution.width * scene->resolution.height * 4;
	write(fd, "BM", 2);
	write(fd, &size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, "6\0\0\0", 4);
	write(fd, "(\0\0\0", 4);
	write(fd, &scene->resolution.width, 4);
	write(fd, &scene->resolution.height, 4);
	write(fd, &pl, 2);
	write(fd, &deep_cl, 2);
	write(fd, &compression, 4);
	write(fd, &image_size, 4);
	write(fd, &scene->resolution.width, 4);
	write(fd, &scene->resolution.height, 4);
	write(fd, "\0\0\0\0\0\0\0\0", 8);
}

void	bmp_file(t_data img, t_scene *scene)
{
	int	fd;
	int	color;
	int	x;
	int	y;

	fd = open("screenshot.bmp", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd < 3)
		return ;
	write_bmp(fd, scene);
	y = scene->resolution.height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x <= (scene->resolution.width - 1))
		{
			color = image_pixel_color(&img, x, y);
			write(fd, &(color), 4);
			x++;
		}
		y--;
	}
}
