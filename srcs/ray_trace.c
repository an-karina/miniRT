/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:47:49 by jhleena           #+#    #+#             */
/*   Updated: 2021/04/06 16:17:31 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_struct.h"
#include "scene.h"

double	discriminant(double a, double b, double c)
{
	return (b * b - 4 * a * c);
}

double		get_t_sphere(t_camera camera, t_sphere sphere)
{
	
}

t_color		ray_trace(t_ray ray, t_scene scene)
{
	double	a;
	double	b;
	double	c;
	double	t_1;
	double	t_2;
	double	disc;
	t_vec	vec_oc;
	t_color	black;
	
	black.r = 0;
	black.g = 0;
	black.b = 255;
	a = vec_dot(ray.direction, ray.direction);
	vec_oc = vec_sub((t_vec)(((t_camera *)((scene.cameras)->data))->position), (t_vec)(((t_sphere *)((t_object *)(scene.objects)->data)->shape)->center));
	b = 2 * vec_dot(ray.direction, vec_oc);
	c = vec_dot(vec_oc, vec_oc) - (((t_sphere *)((t_object *)(scene.objects)->data)->shape)->r * ((t_sphere *)((t_object *)(scene.objects)->data)->shape)->r);
	disc = discriminant(a, b, c);
	//disc = get_t_sphere()
	if (disc < 0)
		return (black);
	t_1 = (-b + sqrt(disc))/(2 * a);
	t_2 = (-b - sqrt(disc))/(2 * a);
	t_1 = (t_1 >= 0 && t_1 > t_2) ? (t_1) : (t_2);
	if (t_1 > 0)
		return (((t_object *)(scene.objects)->data)->color);
	else
		return (black);
}