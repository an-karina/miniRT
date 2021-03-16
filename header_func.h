/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_func.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:42:11 by jhleena           #+#    #+#             */
/*   Updated: 2021/03/16 17:24:39 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_FUNC_H
# define HEADER_FUNC_H

# include "header_struct.h"

t_wind		fill_wind(float height, float width);
t_vec		fill_vector(float x, float y, float z);
t_point		fill_point(float x, float y, float z);
t_camera	fill_camera(t_point p_view, t_vec view, float fov, t_wind window);

#endif