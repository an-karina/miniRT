/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:39:48 by jhleena           #+#    #+#             */
/*   Updated: 2021/03/19 19:16:44 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_STRUCT_H
# define HEADER_STRUCT_H

# include "../mlx/mlx.h"
# include <math.h>

enum				e_figure
{
	SPHERE,
	CYLINDER,
	TRIANGLE,
	PLANE,
	SQUARE,
};


typedef struct		s_window
{
	int				height;
	int				width;
}					t_wind;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef t_point 	t_vec;

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

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;


typedef struct  	s_data {
    void        	*img;
    char        	*addr;
    int         	bits_per_pixel;
    int         	line_length;
    int         	endian;
}               	t_data;

#endif
