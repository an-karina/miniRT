/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:53:48 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/10 22:45:26 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"

typedef struct s_sphere
{
	t_point		center;
	double		r;
}				t_sphere;

typedef struct s_plane
{
	t_point		p;
	t_vec		norm;
}				t_plane;

typedef struct s_square
{
	t_point		center;
	t_vec		norm;
	double		size;
}				t_square;

typedef struct s_cylinder
{
	t_point		center;
	t_vec		norm;
	double		d;
	double		height;	
}				t_cylinder;

typedef struct s_triangle
{
	t_point		first_p;
	t_point		second_p;
	t_point		third_p;
}				t_triangle;

typedef struct s_object
{
	t_color		color;
	void		*shape;
	double		(*intersection)(struct s_object *, t_ray);
	t_vec		(*norm)(double, t_ray, struct s_object);
}				t_object;

#endif
