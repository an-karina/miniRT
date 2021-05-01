/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 15:43:46 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/01 15:45:07 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_struct.h"
#include "vector.h"
#include "object.h"

t_vec			normal_sphere(double t, t_ray ray, t_object object)
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

t_vec			normal_plane(double t, t_ray ray, t_object object)
{
	t_plane *plane;

	plane = (t_plane *)object.shape;
	if (vec_dot(ray.direction, plane->norm) > 0)
		return (vec_mul(plane->norm, -1));
	return (plane->norm);
}
