/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:23:51 by jhleena           #+#    #+#             */
/*   Updated: 2021/03/18 16:41:50 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header_struct.h"
#include "includes/header_fill.h"
#include "includes/vector.h"
#include "includes/camera.h"

int				main(void)
{
	t_camera	camera;
	t_vec		view;
	t_point		point_of_view;
	t_wind		window;

	window = fill_wind(1920, 1080);
	point_of_view = fill_point(0, 0, 0);
	view = fill_vector(0, 0, 1);
	camera = fill_camera(point_of_view, view, (double)80, window);
	return (0);
}
