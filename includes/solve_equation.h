/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_equation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:07:28 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/04 15:26:43 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_EQUATION_H
# define SOLVE_EQUATION_H

#include "object.h"

typedef struct s_coeff
{
	double		a;
	double		b;
	double		c;
}				t_coeff;

typedef struct s_roots
{
	double		t_1;
	double		t_2;
}				t_roots;

double			discriminant(double a, double b, double c);
double			solve_equation_sphere(t_object *object, t_ray ray);
double			solve_equation_plane(t_object *object, t_ray ray);
t_vec			normal_sphere(double t, t_ray ray, t_object object);
t_vec			normal_plane(double t, t_ray ray, t_object object);

#endif
