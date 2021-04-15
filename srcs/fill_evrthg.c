/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_evrthg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:37:51 by jhleena           #+#    #+#             */
/*   Updated: 2021/03/19 17:42:24 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_struct.h"
#include "../includes/camera.h"
#include "../includes/vector.h"

t_wind		fill_wind(double width, double height)
{
	t_wind window;

	window.height = height;
	window.width = width;
	return (window);
}

t_vec		fill_vector(double x, double y, double z)
{
	t_vec vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_point		fill_point(double x, double y, double z)
{
	t_point vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_camera	fill_camera(t_point p_view, t_vec view, double fov, t_wind window)
{
	t_camera	camera;
	t_vec		z;

	camera.position = p_view;
	camera.view = view;
	camera.fov = (M_PI / 180) * fov;
	camera.distance = (window.width / 2) * (tan(camera.fov / 2));
	z = fill_vector(0, 0, 1);
	if (is_null_vec(vec_cross(camera.view, z)))
		z = fill_vector(1, 0, 0);
	camera.base.k = vec_norm(view);
	//camera.base.i = vec_norm(vec_cross(camera.base.k, z));
	camera.base.i = vec_norm(vec_cross(z, camera.base.k));
	camera.base.j = vec_cross(camera.base.i, camera.base.k);
	return (camera);
}
