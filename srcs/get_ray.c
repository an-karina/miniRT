/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:11:04 by jhleena           #+#    #+#             */
/*   Updated: 2021/03/18 21:08:04 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/camera.h"
#include "../includes/vector.h"
#include "../includes/header_struct.h"

t_ray		get_ray(int x, int y, t_camera camera, t_wind winndow)
{
	t_vec local;
	t_ray ret;

	local.x = x - (winndow.width / 2);
	local.y = -y + (winndow.height / 2);
	local.z = camera.distance;
	ret.direction = vec_norm(mat_mul_vec(camera.base, local));
	ret.point = camera.position;
	return (ret);
}
