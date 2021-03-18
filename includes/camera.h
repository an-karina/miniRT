/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:14:47 by jhleena           #+#    #+#             */
/*   Updated: 2021/03/18 21:03:24 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "header_struct.h"
# include "vector.h"

typedef struct		s_camera
{
	t_point			position;
	double			fov;
	t_vec			view;
	double			distance;
	t_matrix		base;
}					t_camera;

#endif
