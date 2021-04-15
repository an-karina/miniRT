/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:47:49 by jhleena           #+#    #+#             */
/*   Updated: 2021/04/08 17:16:40 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_struct.h"
#include "scene.h"
#include "solve_equation.h"
#include "object.h"

double		discriminant(double a, double b, double c)
{
	return (b * b - 4 * a * c);
}

double		solve_equation_sphere(t_object *object, t_ray ray)
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
	roots.t_1 = (roots.t_1 >= 0 && roots.t_1 > roots.t_2) ?
				(roots.t_1) : (roots.t_2);
	return (roots.t_1);
}

double			solve_equation_plane(t_object *object, t_ray ray)
{
	double t;
	t_plane *plane;

	plane = (t_plane *)(object->shape);
	t = vec_dot(vec_sub((t_vec)((plane)->p), (t_vec)ray.point), (plane)->norm);
	t = t / (vec_dot(ray.direction, (plane)->norm));
	return (t);
}

t_color		ambient(t_ambient ambient, t_color color)
{
	t_color intensity;

	intensity.r = ((ambient.color.r / 255) * ambient.intensity) * color.r;
	intensity.g = ((ambient.color.g / 255) * ambient.intensity) * color.g;
	intensity.b = ((ambient.color.b / 255) * ambient.intensity) * color.b;
	return (intensity);
}

t_vec			normal_sphere(double t, t_ray ray, t_object object)
{
	t_vec norm;
	t_sphere *sphere;

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

t_color		lightnig(double t, t_ray ray, t_object *obj_max, t_scene scene)
{
	return (ambient(scene.ambient, obj_max->color));
}

t_color		ray_trace(t_ray ray, t_scene scene)
{
	double		t;
	t_color		black;
	t_object	*object;
	double		t_max;
	t_object	*obj_max;
	t_vec		norm;

	black.r = 0;
	black.g = 0;
	black.b = 50;
	
	t_max = 0;
	while (scene.objects != NULL)
	{
		object = (scene.objects)->content;
		t = (object->intersection)(object, ray);
		if ((t > 0) && (t > t_max))
		{
			t_max = t;
			obj_max = object;
			//norm = (object->normal)(t_max, ray, *obj_max);			
		}
		scene.objects = (scene.objects)->next;
	}
	if (t_max)
		return (lightnig(t_max, ray, obj_max, scene));
	return (black);
}
