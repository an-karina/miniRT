/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:53:48 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/04 11:36:29 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "header_struct.h"

typedef struct s_sphere
{
	t_point		center;
	double		r;
}				t_sphere;

typedef struct s_plane
{
	t_point		p;
	t_vec		norm;
}				t_plane;

typedef struct s_object
{
	t_color		color;
	void		*shape;
	double		(*intersection)(struct s_object *, t_ray);
	t_vec		(*norm)(double, t_ray, struct s_object);
}				t_object;

#endif
