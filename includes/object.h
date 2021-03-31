/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:53:48 by jhleena           #+#    #+#             */
/*   Updated: 2021/03/31 15:45:44 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

#include "header_struct.h"

typedef struct s_sphere
{
	t_point center;
	double	r;
}				t_sphere;


typedef struct	s_object
{
	t_color		color;
	t_sphere	shape;
}				t_object;

#endif