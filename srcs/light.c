/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:20:50 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/02 20:54:41 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_struct.h"
#include "vector.h"
#include "scene.h"
#include "object.h"
#include "solve_equation.h"
#include "light.h"
#include "stdio.h"

t_vec		mul_intensity_color(t_color color, double intensity)
{
	t_vec 		vec;
    
	vec.x = ((double)color.r / 255) * intensity;
	vec.y = ((double)color.g / 255) * intensity;
	vec.z = ((double)color.b / 255) * intensity;
	return (vec);
}

t_vec       light_color(t_light *light, t_vec point, t_vec norm)
{
    t_vec		light_dir;
    t_vec		light_intes;
	double		dot;
    
    light_dir = vec_norm(vec_sub((t_vec)(light->center), point));
    light_intes = mul_intensity_color(light->color,light->intensity);
    dot = vec_dot(norm, light_dir);
	if (dot > 0)
		light_intes = vec_mul(light_intes, dot);
	else
		light_intes = (t_vec){0, 0, 0};
    return (light_intes);
}

t_point		calc_point(t_ray ray, double t)
{
	t_point		point;

	point = vec_mul(ray.direction, t);
	point = vec_add((t_vec)ray.point, point);
	return (point);
}

t_color     calc_res_light(t_vec sum_of_light, t_color obj_color)
{
    t_color color;
    
    color.r = sum_of_light.x  * obj_color.r;
    color.g = sum_of_light.y  * obj_color.g;
    color.b = sum_of_light.z  * obj_color.b;
    return (color);
}

int			shadow(t_vec point, t_point light_center, t_scene scene)
{
	t_ray		ray;
	t_object	*object;
	double		t;
	double		t_closest;
	int			i = -1;
	
	//ray.direction = vec_norm(mat_mul_vec(((t_camera *)(scene.cameras)->content)->base, vec_sub((t_vec)light_center, point)));
	ray.direction = vec_sub((t_vec)light_center, point);
	t_closest = vec_lenght(ray.direction);
	ray.direction = vec_norm(ray.direction);
	ray.point = point;
	while (scene.objects != NULL)
	{
		object = (t_object *)scene.objects->content;
		t = (object->intersection)(object, ray);
		if (t >= eps  && t <= t_closest)
			return (1);
		scene.objects = scene.objects->next;
	}
		return (0);
}

t_color		lightnig(double t, t_ray ray, t_object *obj_max, t_scene scene)
{
	t_color		color;
	t_light		*light;
	t_vec		ambient;
	t_vec		light_intes;
	t_vec		sum_of_lights;

	sum_of_lights = (t_vec){0.0, 0.0, 0.0};
	while (scene.light != NULL)
	{
		light_intes = (t_vec){0, 0, 0};
		light = (t_light *)((scene.light)->content);
		if (shadow((t_vec)calc_point(ray, t), light->center, scene))
		{
			scene.light = (scene.light)->next;
			continue;
		}
        light_intes = light_color(light, (t_vec)calc_point(ray, t), ((*obj_max).normal)(t, ray, *obj_max));
		sum_of_lights = vec_add(sum_of_lights, light_intes);
		scene.light = (scene.light)->next;
	}
	ambient = mul_intensity_color(scene.ambient.color, scene.ambient.intensity);
    color = calc_res_light(vec_add(ambient, sum_of_lights), (*obj_max).color);
	return (color);
}
