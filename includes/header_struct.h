/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:39:48 by jhleena           #+#    #+#             */
/*   Updated: 2021/03/18 16:44:16 by jhleena          ###   ########.fr       */
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

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

typedef	struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_ray
{
	t_point		point;
	t_vec		direction;
}				t_ray;

#endif
