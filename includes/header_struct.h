/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:39:48 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/08 17:01:04 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_STRUCT_H
# define HEADER_STRUCT_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

# define EPS 0.000000001

enum	e_exist
{
	EXISTS,
	DOES_NOT_EXIST
};

typedef struct s_window
{
	int				height;
	int				width;
	enum e_exist	existance;

}					t_wind;

typedef struct s_point
{
	double			x;
	double			y;
	double			z;
	enum e_exist	existance;
}					t_point;

typedef t_point	t_vec;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_ray
{
	t_point		point;
	t_vec		direction;
}				t_ray;

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

#endif
