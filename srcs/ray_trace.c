/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:47:49 by jhleena           #+#    #+#             */
/*   Updated: 2021/03/31 15:53:09 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_struct.h"
#include "scene.h"

double	discriminant(double a, double b, double c)
{
	return (b * b - 4 * a * c);
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
	black.b = 0;
	a = vec_dot(ray.direction, ray.direction);
	vec_oc = vec_sub((t_vec)scene.cameras.position, (t_vec)scene.objects.shape.center);
	b = 2 * vec_dot(ray.direction, vec_oc);
	c = vec_dot(vec_oc, vec_oc) - (scene.objects.shape.r * scene.objects.shape.r);
	disc = discriminant(a, b, c);
	if (disc < 0)
		return (black);
	t_1 = (-b + sqrt(disc))/(2 * a);
	t_2 = (-b - sqrt(disc))/(2 * a);
	t_1 = (t_1 >= 0 && t_1 > t_2) ? (t_1) : (t_2);
	if (t_1 > 0)
		return (scene.objects.color);
	else
		return (black);
}