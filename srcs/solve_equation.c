/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_equation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:59:39 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/23 09:25:29 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve_equation.h"
#include "header_struct.h"
#include "header_fill.h"
#include "scene.h"

double	solve_equation_square(t_object *object, t_ray ray)
{
	t_square	*sq;
	t_matrix	base;
	t_vec		p;
	double		var[3];
	t_vec		z;

	sq = (t_square *)(object->shape);
	var[2] = vec_dot(vec_sub((t_vec)((sq)->center),
				(t_vec)ray.point), (sq)->norm);
	if (vec_dot(ray.dir, sq->norm) == 0.0)
		return (-1);
	var[2] = var[2] / (vec_dot(ray.dir, (sq)->norm));
	z = fill_vector(0, 0, 1);
	if (is_null_vec(vec_cross(z, sq->norm)))
		z = fill_vector(0, 1, 0);
	base.k = sq->norm;
	base.i = vec_norm(vec_cross(z, base.k));
	base.j = vec_cross(base.k, base.i);
	p = vec_sub((t_vec)calc_point(ray, var[2]), (t_vec)sq->center);
	var[0] = vec_dot(base.i, p);
	var[1] = vec_dot(base.j, p);
	if ((var[0] <= (sq->size / 2)) && (var[0] >= (-sq->size / 2))
		&& (var[1] <= (sq->size / 2)) && (var[1] >= (-sq->size / 2)))
		return (var[2]);
	return (-1);
}

double	solve_equation_triangle(t_object *object, t_ray ray)
{
	t_triangle	*triangle;
	t_vec		vec;
	double		t;
	t_coeff		coeff;
	double		d[2];

	triangle = (t_triangle *)object->shape;
	d[0] = vec_dot(ray.dir, triangle->norm);
	if (d[0] == 0)
		return (-1);
	d[1] = vec_dot(vec_cross(ray.dir, triangle->edge_ft), triangle->edge_fs);
	if (d[1] == 0)
		return (-1);
	vec = vec_sub(ray.point, triangle->first_p);
	t = vec_dot(vec_cross(vec, triangle->edge_fs), triangle->edge_ft) / d[1];
	coeff.a = vec_dot(vec_cross(ray.dir, triangle->edge_ft), vec) / d[1];
	coeff.b = vec_dot(vec_cross(vec, triangle->edge_fs), ray.dir) / d[1];
	if (t >= EPS && coeff.a >= 0 && coeff.b >= 0 && coeff.a + coeff.b <= 1)
		return (t);
	return (-1);
}

double	give_nearest_t(double t_1, double t_2)
{
	if ((t_1 > EPS) && (t_2 > EPS))
	{
		if (t_1 > t_2)
			return (t_2);
		return (t_1);
	}
	else if (t_1 > EPS)
		return (t_1);
	else if (t_2 > EPS)
		return (t_2);
	return (-1);
}

t_roots	find_root(t_ray ray, t_cylinder *cylinder, t_vec co)
{
	t_coeff	coeff;
	t_roots	roots;
	double	disc;
	
	roots.exist = EXISTS;
	coeff.a = vec_dot(ray.dir, ray.dir)
		- vec_dot(cylinder->norm, ray.dir) * vec_dot(cylinder->norm, ray.dir);
	coeff.b = 2 * (vec_dot(co, ray.dir) - vec_dot(cylinder->norm, co) * vec_dot(cylinder->norm, ray.dir));
	coeff.c = vec_dot(co, co) - vec_dot(cylinder->norm, co) * vec_dot(cylinder->norm, co) - (cylinder->d * cylinder->d / 4);
	disc = discriminant(coeff.a, coeff.b, coeff.c);
	if (disc < 0)
	{
		roots.exist = DOES_NOT_EXIST;
		return (roots);
	}
	roots.t_1 = (-coeff.b + sqrt(disc)) / (2 * coeff.a);
	roots.t_2 = (-coeff.b - sqrt(disc)) / (2 * coeff.a);
	return (roots);
}

double	solve_equation_cylinder(t_object *object, t_ray ray)
{
	t_roots		roots;
	t_vec		co;
	t_vec		intersect[2];
	t_cylinder	*cylinder;
	double		h;

	cylinder = (t_cylinder *)object->shape;
	co = vec_sub((t_vec)ray.point, (t_vec)cylinder->center);
	roots = find_root(ray, cylinder, co);
	if (roots.exist != EXISTS)
		return (-1);
	intersect[0] = vec_sub(calc_point(ray, roots.t_1), cylinder->center);
	intersect[1] = vec_sub(calc_point(ray, roots.t_2), cylinder->center);
	h = vec_dot(intersect[0], cylinder->norm);
	if (h > cylinder->height / 2 || h < -cylinder->height / 2)
		roots.t_1 = -1;
	h = vec_dot(intersect[1], cylinder->norm);
	if (h > cylinder->height / 2 || h < -cylinder->height / 2)
		roots.t_2 = -1;
	roots.t_1 = give_nearest_t(roots.t_1, roots.t_2);
	return (roots.t_1);
}
