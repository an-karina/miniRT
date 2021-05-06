/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:21:52 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/06 17:10:02 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "scene.h"
#include <stdio.h>

t_scene	parse_resolution(t_scene scene, char *str);
t_scene	parse_ambient(t_scene scene, char *str);
t_scene	parse_camera();
t_scene	parse_light();
t_scene	parse_sphere();
t_scene parse_plane();
t_scene	parse_square();
t_scene	parse_cylinder();
t_scene	parse_triangle();
t_scene	parse_id(t_scene scene, char *str);
t_scene	parser(char *file_name);
t_scene	fill_scene_null(t_scene scene);
char	*ft_is_space(char *str);
int		num_length(int num);
int		correct_input(char *str);

#endif