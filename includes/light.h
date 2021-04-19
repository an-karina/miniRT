/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:17:27 by jhleena           #+#    #+#             */
/*   Updated: 2021/04/08 17:08:59 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "header_struct.h"

typedef struct	s_ambient
{
	double		intensity;
	t_color		color;
}				t_ambient;

typedef struct s_light
{
	t_point		center;
	double		intensity;
	t_color		color;
}				t_light;

int				rgb_to_int(t_color color);

#endif