/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_equation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:07:28 by jhleena           #+#    #+#             */
/*   Updated: 2021/04/08 15:20:57 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_EQUATION_H
# define SOLVE_EQUATION_H

typedef struct	s_coeff
{
	double		a;
	double		b;
	double		c;
}				t_coeff;

typedef struct	s_roots
{
	double		t_1;
	double		t_2;
}				t_roots;

double			discriminant(double a, double b, double c);
double			solve_equation_sphere(t_camera *camera, t_object *object, t_ray ray);
double			solve_equation_plane(t_camera *camera, t_object *object, t_ray ray);
#endif
