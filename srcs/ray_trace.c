/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@pashalove.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:47:49 by jhleena           #+#    #+#             */
/*   Updated: 2021/04/08 15:23:00 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_struct.h"
#include "scene.h"
#include "solve_equation.h"

double		discriminant(double a, double b, double c)
{
	return (b * b - 4 * a * c);
}

double		solve_equation(t_camera *camera, t_sphere *sphere, t_ray ray)
{
	t_coeff coeff;
	t_roots roots;
	double	disc;
	t_vec	vec_oc;
	
	coeff.a = vec_dot(ray.direction, ray.direction);
	vec_oc = vec_sub((t_vec)(camera->position), (t_vec)(sphere->center));
	coeff.b = 2 * vec_dot(ray.direction, vec_oc);
	coeff.c = vec_dot(vec_oc, vec_oc) - (sphere->r * sphere->r);
	disc = discriminant(coeff.a, coeff.b, coeff.c);
	if (disc < 0)
		return (-1);
	roots.t_1 = (-coeff.b + sqrt(disc))/(2 * coeff.a);
	roots.t_2 = (-coeff.b - sqrt(disc))/(2 * coeff.a);
	roots.t_1 = (roots.t_1 >= 0 && roots.t_1 > roots.t_2) ? 
				(roots.t_1) : (roots.t_2);
	return (roots.t_1);
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
		t_1 = solve_equation((t_camera *)((scene.cameras)->content), (t_sphere *)((t_object *)(scene.objects)->content)->shape, ray);
		if (t_1 >= 0)
			return (((t_object *)(scene.objects)->content)->color);
		scene.objects = (scene.objects)->next;
	}
	return (black);
}