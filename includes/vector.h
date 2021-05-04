/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:21:17 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/04 11:40:32 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "header_struct.h"

typedef struct s_matrix
{
	t_vec	i;
	t_vec	j;
	t_vec	k;
}			t_matrix;

t_vec		vec_add(t_vec u, t_vec v);
t_vec		vec_sub(t_vec u, t_vec v);
t_vec		vec_mul(t_vec u, double t);
t_vec		vec_div(t_vec u, double t);
double		vec_dot(t_vec u, t_vec v);
t_vec		vec_cross(t_vec u, t_vec v);
t_vec		vec_norm(t_vec vec);
double		vec_lenght(t_vec vec);
double		vec_lenght_2(t_vec vec);
t_vec		mat_mul_vec(t_matrix m, t_vec v);
int			is_null_vec(t_vec v);
t_vec		res_light(t_vec sum_of_light, t_color obj_color);

#endif
