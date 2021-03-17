/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    vector_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:18:29 by jhleena           #+#    #+#             */
/*   Updated: 2021/03/17 20:29:53 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vector.h"

t_vec	vec_add(t_vec u, t_vec v)
{
	t_vec sum;

	sum.x = u.x + v.x;
	sum.y = u.y + v.y;
	sum.z = u.z + v.z;
	return (sum);
}

t_vec	vec_sub(t_vec u, t_vec v)
{
	t_vec sum;

	sum.x = u.x - v.x;
	sum.y = u.y - v.y;
	sum.z = u.z - v.z;
	return (sum);
}

t_vec	vec_mul(t_vec u, double t)
{
	t_vec sum;

	sum.x = u.x * t;
	sum.y = u.y * t;
	sum.z = u.z * t;
	return (sum);
}

double	vec_dot(t_vec u, t_vec v)
{
	return (u.x * v.x + u.y *v.y + u.z * v.z);
}

t_vec	vec_cross(t_vec u, t_vec v)
{
	t_vec sum;

	sum.x = u.y * v.z - u.x * v.y;
	sum.y = u.x * v.z - u.z * v.x;
	sum.z = u.x * v.y - u.y * v.x;
	return (sum);
}
