/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_evrthg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:37:51 by jhleena           #+#    #+#             */
/*   Updated: 2021/03/16 18:07:07 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_struct.h"

t_vec		normilize(t_vec vec)
{
	double	module;

	module = sqrt();
}

t_wind		fill_wind(double height, double width)
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
	t_camera camera;

	camera.position = p_view;
	camera.view = fill_vector(view.x, view.y, view.z);
	camera.fov = (M_PI / 180) * fov;
	
	return (camera);
}
