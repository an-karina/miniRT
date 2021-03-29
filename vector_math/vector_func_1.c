/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_func_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:50:53 by jhleena           #+#    #+#             */
/*   Updated: 2021/03/25 16:28:40 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"

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

t_vec	vec_div(t_vec u, double t)
{
	t_vec sum;

	sum.x = u.x / t;
	sum.y = u.y / t;
	sum.z = u.z / t;
	return (sum);
}

double	vec_dot(t_vec u, t_vec v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}
