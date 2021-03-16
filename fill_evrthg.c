/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_evrthg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:37:51 by jhleena           #+#    #+#             */
/*   Updated: 2021/03/16 17:24:24 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_struct.h"

t_wind		fill_wind(float height, float width)
{
	t_wind window;

	window.height = height;
	window.width = width;
	return (window);
}

t_vec		fill_vector(float x, float y, float z)
{
	t_vec vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_point		fill_point(float x, float y, float z)
{
	t_point vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_camera	fill_camera(t_point p_view, t_vec view, float fov, t_wind window)
{
	t_camera camera;

	camera.position = p_view;
	camera.view = fill_vector(view.x, view.y, view.z);
	camera.fov = (M_PI / 180) * fov;
	
	return (camera);
}
