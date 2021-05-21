/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 15:43:46 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/21 09:58:00 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_struct.h"
#include "vector.h"
#include "object.h"
#include "scene.h"
#include <stdio.h>

t_vec	normal_sphere(double t, t_ray ray, t_object object)
{
	t_vec		norm;
	t_sphere	*sphere;

	sphere = (t_sphere *)(object.shape);
	norm = vec_add((t_vec)ray.point, vec_mul(ray.direction, t));
	norm = vec_sub(norm, (t_vec)(sphere->center));
	norm = vec_norm(norm);
	if (vec_dot(ray.direction, norm) > 0)
		norm = vec_mul(norm, -1);
	return (norm);
}

t_vec	normal_plane(double t, t_ray ray, t_object object)
{
	t_plane	*plane;

	plane = (t_plane *)object.shape;
	if (vec_dot(ray.direction, plane->norm) > 0)
		return (vec_mul(plane->norm, -1));
	return (plane->norm);
}

t_vec			normal_square(double t, t_ray ray, t_object object)
{
	t_square	*square;

	square = (t_square *)object.shape;
	if (vec_dot(ray.direction, square->norm) > 0)
		return (vec_mul(square->norm, -1));
	return (square->norm);
}

t_vec			normal_cylinder(double t, t_ray ray, t_object object)
{
	t_cylinder	*cylinder;
	t_vec		norm;
	t_vec		po;
	t_vec		vec;

	cylinder = (t_cylinder *)object.shape;
	po =  vec_sub((t_vec)calc_point(ray, t), (t_vec)cylinder->center);
	vec = vec_cross(po, cylinder->norm);
	printf("|%lf, %lf, %lf|\n", cylinder->norm.x, cylinder->norm.y, cylinder->norm.z);
	if (vec_dot(ray.direction, norm) > 0)
		return (vec_mul(norm, -1));
	return (norm);
}

t_vec			normal_triangle(double t, t_ray ray, t_object object)
{
	t_triangle	*triangle;

	triangle = (t_triangle *)object.shape;
	if (vec_dot(ray.direction, triangle->norm) > 0)
		return (vec_mul(triangle->norm, -1));
	return (triangle->norm);
}
