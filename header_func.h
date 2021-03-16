/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_func.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:42:11 by jhleena           #+#    #+#             */
/*   Updated: 2021/03/16 18:06:28 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_FUNC_H
# define HEADER_FUNC_H

# include "header_struct.h"

t_wind		fill_wind(double height, double width);
t_vec		fill_vector(double x, double y, double z);
t_point		fill_point(double x, double y, double z);
t_camera	fill_camera(t_point p_view, t_vec view, double fov, t_wind window);

#endif