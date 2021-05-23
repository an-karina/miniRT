/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_func_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:05:12 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/23 16:54:38 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"

t_vec	vec_cross(t_vec u, t_vec v)
{
	t_vec	sum;

	sum.x = u.y * v.z - u.z * v.y;
	sum.y = u.z * v.x - u.x * v.z;
	sum.z = u.x * v.y - u.y * v.x;
	return (sum);
}

t_vec	vec_norm(t_vec vec)
{
	double	module;

	module = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	vec.x /= module;
	vec.y /= module;
	vec.z /= module;
	return (vec);
}

double	vec_lenght(t_vec vec)
{
	return (sqrt(vec_dot(vec, vec)));
}

double	vec_lenght_2(t_vec vec)
{
	return (vec_dot(vec, vec));
}

t_vec	mat_mul_vec(t_matrix m, t_vec v)
{
	t_vec	u;

	u.x = m.i.x * v.x + m.i.y * v.y + m.i.z * v.z;
	u.y = m.j.x * v.x + m.j.y * v.y + m.j.z * v.z;
	u.z = m.k.x * v.x + m.k.y * v.y + m.k.z * v.z;
	return (u);
}
