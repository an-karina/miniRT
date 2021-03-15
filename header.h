/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:39:48 by jhleena           #+#    #+#             */
/*   Updated: 2021/03/15 21:16:26 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma HEADER_H

	#include "mlx/mlx.h"

	typedef struct	t_vec
	{
		float	x;
		float	y;
		float	z;
	}				s_vec;

	typedef struct	t_point
	{
		float	x;
		float	y;
		float	z;
	}				s_point;

	typedef struct t_ray
	{
		s_point	point;
		s_vec	direction;
	}				s_ray;

	typedef struct t_figure
	{
		float	sphere_r;
		float	point;
	};
	
	
