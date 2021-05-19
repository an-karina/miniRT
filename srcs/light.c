/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:20:50 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/19 18:52:51 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_struct.h"
#include "vector.h"
#include "scene.h"
#include "object.h"
#include "solve_equation.h"
#include "light.h"
#include "stdio.h"

t_vec	mul_intens_color(t_color color, double intensity)
{
	t_vec		vec;

	vec.x = ((double)color.r / 255) * intensity;
	vec.y = ((double)color.g / 255) * intensity;
	vec.z = ((double)color.b / 255) * intensity;
	return (vec);
}

t_point	calc_point(t_ray ray, double t)
{
	t_point		point;

	point = vec_mul(ray.direction, t);
	point = vec_add((t_vec)ray.point, point);
	return (point);
}

int	shadow(t_vec point, t_point light_center, t_scene scene)
{
	t_ray		ray;
	t_object	*object;
	double		t;
	double		t_closest;

	ray.direction = vec_sub((t_vec)light_center, point);
	t_closest = vec_lenght(ray.direction);
	ray.direction = vec_norm(ray.direction);
	ray.point = point;
	while (scene.objects != NULL)
	{
		object = (t_object *)scene.objects->content;
		t = (object->intersection)(object, ray);
		if (t >= EPS && t <= t_closest)
			return (1);
		scene.objects = scene.objects->next;
	}
	return (0);
}

t_vec	lightcolor(t_light *light, t_vec point, t_vec norm)
{
	t_vec		light_dir;
	t_vec		light_intes;
	double		dot;

	light_dir = vec_norm(vec_sub((t_vec)(light->center), point));
	light_intes = mul_intens_color(light->color, light->intensity);
	dot = vec_dot(norm, light_dir);
	if (dot > 0)
		light_intes = vec_mul(light_intes, dot);
	else
		light_intes = (t_vec){0, 0, 0};
	return (light_intes);
}

t_color	lightnig(double t, t_ray ray, t_object *obj, t_scene scene)
{
	t_vec		color;
	t_light		*light;
	t_vec		point;
	t_vec		light_intes;
	t_vec		sum_of_lights;

	sum_of_lights = (t_vec){0.0, 0.0, 0.0};
	point = (t_vec)calc_point(ray, t);
	while (scene.light != NULL)
	{
		light_intes = (t_vec){0, 0, 0};
		light = (t_light *)((scene.light)->content);
		if (!shadow(point, light->center, scene))
		{
			light_intes = lightcolor(light, point, ((*obj).norm)(t, ray, *obj));
			sum_of_lights = vec_add(sum_of_lights, light_intes);
		}
		scene.light = (scene.light)->next;
	}
	color = mul_intens_color(scene.amb.color, scene.amb.intensity);
	color = vec_add(color, sum_of_lights);
	color = res_light(color, (*obj).color);
	return ((t_color){color.x, color.y, color.z}
	);
}
