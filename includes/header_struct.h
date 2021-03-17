/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:39:48 by jhleena           #+#    #+#             */
/*   Updated: 2021/03/17 19:31:43 by jhleena          ###   ########.fr       */
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
	int			height;
	int			width;
}				t_wind;


typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;
typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef	struct		s_color
{
	int				r;
	int				g;
	int				b;
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
	double			fov;
	t_vec			view;
	double			distance;
	t_bais			base;
}					t_camera;

typedef struct		s_object
{
	double			s_diameter;
	t_vec			normal;
	double			side_size;
	double			c_height;
	double			c_diameter;
	t_point			x_point;
	t_point			y_point;
	t_point			z_point;
	t_color			color;
	t_camera		camera;
	enum e_figure	id;
}					t_object;

#endif
