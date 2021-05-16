/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_equation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:59:39 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/16 14:48:21 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve_equation.h"
#include "header_struct.h"
#include "header_fill.h"
#include "scene.h"

double	solve_equation_square(t_object *object, t_ray ray)
{
	double		t;
	t_square	*square;
	t_matrix	base;
	t_vec		p;
	double		dot[2];
	t_vec		z;

	square = (t_square *)(object->shape);
	t = vec_dot(vec_sub((t_vec)((square)->center), (t_vec)ray.point), (square)->norm);
	if (vec_dot(ray.direction, (square)->norm) > 0.000000001)
		t = t / (vec_dot(ray.direction, (square)->norm));
	else
		return (-1);
	z = fill_vector(0,0,1);
	
	if (is_null_vec(vec_cross(z, square->norm)))
		z = fill_vector(0, 1, 0);
	base.k = square->norm;
	base.i = vec_norm(vec_cross(z, base.k));
	base.j = vec_cross(base.k, base.i);
	p = vec_sub((t_vec)calc_point(ray, t), (t_vec)square->center);
	dot[0] = vec_dot(base.i, p);
	dot[1] = vec_dot(base.j, p);
	if ((dot[0] <= (square->size / 2)) && (dot[0] >= (-square->size / 2)) &&
			(dot[1] <= (square->size / 2)) && (dot[1] >= (-square->size / 2)))
		return (t);
	return (-1);
}
