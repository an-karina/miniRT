/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:20:50 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/01 14:09:00 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_struct.h"
#include "vector.h"
#include "scene.h"
#include "object.h"
#include "light.h"

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

t_vec		intensity(t_color color, double intensity)
{
	t_vec vec;
    
	vec.x = ((double)color.r / 255) * intensity;
	vec.y = ((double)color.g / 255) * intensity;
	vec.z = ((double)color.b / 255) * intensity;
	return (vec);
}

t_point		calculate_point(t_ray ray, double t)
{
	t_point		point;

	point = vec_mul(ray.direction, t);
	point = vec_add((t_vec)ray.point, point);
	return (point);
}

t_vec       light_color(t_light *light, t_vec point, t_vec norm)
{
    t_vec		light_direction;
    t_vec		light_intes;
	double		dot;
    
    light_direction = vec_norm(vec_sub((t_vec)(light->center), point));
    light_intes = intensity(light->color,light->intensity);
    dot = vec_dot(norm, light_direction);
	if (dot > 0)
		light_intes = vec_mul(light_intes, dot);
	else
		light_intes = (t_vec){0, 0, 0};
    return (light_intes);
}

t_color     calculate_result_light(t_vec sum_of_light, t_color obj_color)
{
    t_color color;
    
    color.r = sum_of_light.x  * obj_color.r;
    color.g = sum_of_light.y  * obj_color.g;
    color.b = sum_of_light.z  * obj_color.b;
    return (color);
}

t_color		lightnig(double t, t_ray ray, t_object *obj_max, t_scene scene)
{
	t_color		color;
	t_light		*light;
	t_vec		ambient;
	t_vec		light_intes;
	t_vec		sum_of_light;

	sum_of_light = (t_vec){0.0, 0.0, 0.0};
	while (scene.light != NULL)
	{
		light_intes = (t_vec){0, 0, 0};
		light = (t_light *)((scene.light)->content);
        light_intes = light_color(light, (t_vec)calculate_point(ray, t), ((*obj_max).normal)(t, ray, *obj_max));
		sum_of_light = vec_add(sum_of_light, light_intes);
		scene.light = (scene.light)->next;
	}
	ambient = intensity(scene.ambient.color, scene.ambient.intensity);
    color = calculate_result_light(vec_add(ambient, sum_of_light), (*obj_max).color);
	return (color);
}