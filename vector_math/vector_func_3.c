/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_func_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:37:51 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/03 15:32:45 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"

int			is_null_vec(t_vec vec)
{
	if (vec.x == 0 && vec.y == 0 && vec.z == 0)
		return (1);
	return (0);
}

t_vec		res_light(t_vec sum_of_light, t_color obj_color)
{
	t_vec	color;

	color.x = sum_of_light.x * obj_color.r;
	color.y = sum_of_light.y * obj_color.g;
	color.z = sum_of_light.z * obj_color.b;
	return (color);
}
