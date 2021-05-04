/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:47:49 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/04 12:06:31 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_struct.h"
#include "scene.h"
#include "solve_equation.h"
#include "object.h"

double	discriminant(double a, double b, double c)
{
	return (b * b - 4 * a * c);
}

double	solve_equation_sphere(t_object *object, t_ray ray)
{
	t_coeff		coeff;
	t_roots		roots;
	double		disc;
	t_vec		vec_oc;
	t_sphere	*sphere;

	sphere = (t_sphere *)(object->shape);
	coeff.a = vec_dot(ray.direction, ray.direction);
	vec_oc = vec_sub((t_vec)(ray.point), (t_vec)(sphere->center));
	coeff.b = 2 * vec_dot(ray.direction, vec_oc);
	coeff.c = vec_dot(vec_oc, vec_oc) - (sphere->r * sphere->r);
	disc = discriminant(coeff.a, coeff.b, coeff.c);
	if (disc < 0)
		return (-1);
	roots.t_1 = (-coeff.b + sqrt(disc)) / (2 * coeff.a);
	roots.t_2 = (-coeff.b - sqrt(disc)) / (2 * coeff.a);
	if (roots.t_2 >= 0 && roots.t_1 > 0 && roots.t_2 < roots.t_1)
		roots.t_1 = roots.t_2;
	return (roots.t_1);
}

double	solve_equation_plane(t_object *object, t_ray ray)
{
	double		t;
	t_plane		*plane;

	plane = (t_plane *)(object->shape);
	t = vec_dot(vec_sub((t_vec)((plane)->p), (t_vec)ray.point), (plane)->norm);
	if (vec_dot(ray.direction, (plane)->norm) > 0.000000001)
		t = t / (vec_dot(ray.direction, (plane)->norm));
	else
		return (-1);
	return (t);
}

t_color	ray_trace(t_ray ray, t_scene scene)
{
	double		t;
	t_object	*object;
	double		t_closest;
	t_object	*obj_closest;
	t_list		*tmp;

	obj_closest = (t_object *)(scene.objects)->content;
	t_closest = INFINITY;
	tmp = scene.objects;
	while (scene.objects != NULL)
	{
		object = (t_object *)(scene.objects)->content;
		t = (object->intersection)(object, ray);
		if ((t > 0) && (t <= t_closest))
		{
			t_closest = t;
			obj_closest = object;
		}
		scene.objects = scene.objects->next;
	}
	scene.objects = tmp;
	if (t_closest < INFINITY)
		return (lightnig(t_closest, ray, obj_closest, scene));
	return ((t_color){0, 0, 0});
}
