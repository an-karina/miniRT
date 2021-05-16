/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:11:04 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/16 20:32:34 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "vector.h"
#include "header_struct.h"

t_ray	get_ray(int x, int y, t_camera camera, t_wind window)
{
	t_vec	local;
	t_ray	ret;

	local.x = x - (window.width / 2);
	local.y = -y + (window.height / 2);
	local.z = camera.distance;
	ret.direction = vec_norm(mat_mul_vec(camera.base, local));
	ret.point = camera.position;
	return (ret);
}
