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
	roots.t_1 = (roots.t_2 >= 0 && roots.t_1 > 0 && roots.t_2 < roots.t_1) ?
				(roots.t_2) : (roots.t_1);
	return (roots.t_1);
}

double			solve_equation_plane(t_object *object, t_ray ray)
{
	double t;
	t_plane *plane;

	plane = (t_plane *)(object->shape);
	
	t = vec_dot(vec_sub((t_vec)((plane)->p), (t_vec)ray.point), (plane)->norm);
	if (vec_dot(ray.direction, (plane)->norm) > 0.000000001)
		t = t / (vec_dot(ray.direction, (plane)->norm));
	else
		return (-1);
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

// t_color		lightnig(double t, t_ray ray, t_object *obj_max, t_scene scene)
// {
// 	return (ambient(scene.ambient, obj_max->color));
// }

t_vec		intensity(t_color color, double intensity)
{
	t_vec vec;
	vec.x = ((double)color.r / 255) * intensity;
	vec.y = ((double)color.g / 255) * intensity;
	vec.z = ((double)color.b / 255) * intensity;
	return (vec);
}

t_color		lightnig(double t, t_ray ray, t_object *obj_max, t_scene scene)
{
	t_color		color;
	t_vec		norm;
	t_vec		point;
	t_light		*light;
	t_vec		ambient;
	t_vec		light_intes;
	t_vec		light_direction;
	double		dot_n_l;

	light = (t_light *)((scene.light)->content);
	ambient = intensity(scene.ambient.color, scene.ambient.intensity);
	norm = ((*obj_max).normal)(t, ray, *obj_max);
	//P = O + td; 
	point = vec_mul(ray.direction, t);
	point = vec_add((t_vec)ray.point, point);

	light_direction = vec_sub((t_vec)(light->center), point);
	light_direction = vec_norm(light_direction);

	light_intes = intensity(light->color,light->intensity);
	dot_n_l = vec_dot(norm, light_direction);
	if (dot_n_l > 0)
		light_intes = vec_mul(light_intes, dot_n_l);
	else
	{
		light_intes.x = 0;
		light_intes.y = 0;
		light_intes.z = 0;
	}

	color.r = (ambient.x + light_intes.x) * (*obj_max).color.r;
	color.g = (ambient.y + light_intes.y) * (*obj_max).color.g;
	color.b = (ambient.z + light_intes.z) * (*obj_max).color.b;
	return (color);
}

t_color		ray_trace(t_ray ray, t_scene scene)
{
	double		t;
	t_color		black;
	t_object	*object;
	double		t_closest;
	t_object	*obj_closest;
	t_vec		norm;

	black.r = 0;
	black.g = 0;
	black.b = 0;

	obj_closest = (scene.objects)->content;
	//t_closest = (obj_closest->intersection)(obj_closest, ray);
	t_closest = INFINITY;
	while (scene.objects != NULL)
	{
		object = (scene.objects)->content;
		t = (object->intersection)(object, ray);
		if ((t > 0) && (t <= t_closest))
		{
			t_closest = t;
			obj_closest = object;
			//norm = (object->normal)(t_max, ray, *obj_max);
		}
		scene.objects = (scene.objects)->next;
	}
	if (t_closest < INFINITY)
		return (lightnig(t_closest, ray, obj_closest, scene));
	return (black);
}
