/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:14:47 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/08 16:34:44 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector.h"

typedef struct s_camera
{
	t_point			position;
	double			fov;
	t_vec			view;
	double			distance;
	t_matrix		base;
	enum e_exist	existance;
}					t_camera;

#endif
