/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:47:49 by jhleena           #+#    #+#             */
/*   Updated: 2021/04/06 19:16:47 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_struct.h"
#include "scene.h"

double		discriminant(double a, double b, double c)
{
	return (b * b - 4 * a * c);
}

double		solve_equation(t_camera *camera, t_sphere *sphere, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	double	t_1;
	double	t_2;
	double	disc;
	t_vec	vec_oc;
	
	a = vec_dot(ray.direction, ray.direction);
	vec_oc = vec_sub((t_vec)(camera->position), (t_vec)(sphere->center));
	b = 2 * vec_dot(ray.direction, vec_oc);
	c = vec_dot(vec_oc, vec_oc) - (sphere->r * sphere->r);
	disc = discriminant(a, b, c);
	if (disc < 0)
		return (-1);
	t_1 = (-b + sqrt(disc))/(2 * a);
	t_2 = (-b - sqrt(disc))/(2 * a);
	t_1 = (t_1 >= 0 && t_1 > t_2) ? (t_1) : (t_2);
	return (t_1);
}

t_color		ray_trace(t_ray ray, t_scene scene)
{
	double	t_1;
	t_color	black;
	
	black.r = 0;
	black.g = 0;
	black.b = 255;
	while (scene.objects != NULL)
	{
		t_1 = -1;
		t_1 = solve_equation((t_camera *)((scene.cameras)->data), (t_sphere *)((t_object *)(scene.objects)->data)->shape, ray);
		if (t_1 >= 0)
			return (((t_object *)(scene.objects)->data)->color);
		scene.objects = (scene.objects)->next;
	}
	return (black);
}