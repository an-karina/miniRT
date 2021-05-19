/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_equation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:59:39 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/19 19:33:38 by jhleena          ###   ########.fr       */
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
	if (vec_dot(ray.direction, square->norm) != 0.0)
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

double	solve_equation_triangle(t_object *object, t_ray ray)
{
	double		dot;
	t_triangle	*triangle;
	t_vec		vertice;
	double		t;
	double		alpha;
	double		betta;
	double		determinant;

	triangle = (t_triangle *)object->shape;
	dot = vec_dot(ray.direction,triangle->norm);
	if (dot == 0)
		return (-1);
	determinant = vec_dot(vec_cross(ray.direction, triangle->edge_ft), triangle->edge_fs);
	if (determinant <= 0)
		return (-1);
	vertice = vec_sub(ray.point, triangle->first_p);
	t = vec_dot(vec_cross(vertice, triangle->edge_fs), triangle->edge_ft) / determinant;
	alpha = vec_dot(vec_cross(ray.direction, triangle->edge_ft), vertice) / determinant;
	betta = vec_dot(vec_cross(vertice, triangle->edge_fs), ray.direction) / determinant;
	if (alpha > 1 || betta > 1 || alpha + betta > 1
		|| alpha < 0 || betta < 0 || alpha + betta < 0 || t < 0)
		return (-1);
	return (t);
}

double			solve_equation_cylinder(t_object *object, t_ray ray)
{
	t_coeff		coeff;
	t_roots		roots;
	t_vec		co;
	t_vec		intersect_1;
	t_vec		intersect_2;
	t_cylinder	*cylinder;
	double		disc;
	double		h;

	cylinder = (t_cylinder *)object->shape;
	coeff.a = vec_dot(cylinder->norm, ray.direction);
	coeff.a = vec_dot(ray.direction, ray.direction) - coeff.a * coeff.a;
	co = vec_sub(ray.point, cylinder->center);
	coeff.b = vec_dot(cylinder->norm, co) * vec_dot(cylinder->norm, ray.direction);
	coeff.b = 2 * (vec_dot(co, ray.direction) - coeff.b);
	coeff.c = vec_dot(cylinder->norm, co);
	coeff.c = vec_dot(co,co) - coeff.c * coeff.c - (cylinder->d * cylinder->d / 4);
	disc = discriminant(coeff.a, coeff.b, coeff.c);
	if (disc < 0)
		return (-1);
	roots.t_1 = (-coeff.b + sqrt(disc)) / (2 * coeff.a);
	roots.t_2 = (-coeff.b - sqrt(disc)) / (2 * coeff.a);
	intersect_1 = vec_sub(calc_point(ray, roots.t_1), cylinder->center);
	intersect_2 = vec_sub(calc_point(ray, roots.t_2), cylinder->center);
	h = vec_dot(intersect_1, cylinder->norm);
	if (h > cylinder->height / 2 || h < -cylinder->height / 2)
		return (-1);
	h = vec_dot(intersect_2, cylinder->norm);
	if (h > cylinder->height / 2 || h < -cylinder->height / 2)
		return (-1);
	if (roots.t_2 >= 0 && roots.t_1 > 0 && roots.t_2 < roots.t_1)
		roots.t_1 = roots.t_2;
	return (roots.t_1);
}
