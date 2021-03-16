/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:39:48 by jhleena           #+#    #+#             */
/*   Updated: 2021/03/16 17:11:07 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_STRUCT_H
# define HEADER_STRUCT_H

# include "mlx/mlx.h"
# include "math.h"
# include <stdio.h>

enum			e_figure
{
	SPHERE,
	CYLINDER,
	TRIANGLE,
	PLANE,
	SQUARE,
};

typedef struct	s_window
{
	float	height;
	float	width;
}				t_wind;


typedef struct		s_vec
{
	float			x;
	float			y;
	float			z;
}					t_vec;
typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
}					t_point;

typedef	struct		s_color
{
	float			r;
	float			g;
	float			b;
}					t_color;

typedef struct		s_ray
{
	t_point			point;
	t_vec			direction;
}					t_ray;

typedef struct		s_basis
{
	t_vec			i;
	t_vec			j;
	t_vec			k;
}					t_bais;

typedef struct		s_camera
{
	t_point			position;
	float			fov;
	t_vec			view;
	double			distance;
	t_bais			camera_base;
}					t_camera;

typedef struct		s_figure
{
	float			s_diameter;
	t_vec			normal;
	float			side_size;
	float			c_height;
	float			c_diameter;
	t_point			x_point;
	t_point			y_point;
	t_point			z_point;
	t_color			color;
	t_camera		camera;
	enum e_figure	id;
}					t_figure;

#endif
