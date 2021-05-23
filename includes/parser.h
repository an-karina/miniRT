/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:21:52 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/23 16:51:37 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "scene.h"
# include "solve_equation.h"

void	ft_is_space(char **str);
void	parse_resolution(t_scene *scene, char *str);
void	parse_ambient(t_scene *scene, char *str);
void	parse_camera(t_scene *scene, char *str);
void	parse_light(t_scene *scene, char *str);
void	parse_sphere(t_scene *scene, char *str);
void	parse_plane(t_scene *scene, char *str);
void	parse_square(t_scene *scene, char *str);
void	parse_cylinder(t_scene *scene, char *str);
void	parse_triangle(t_scene *scene, char *str);
void	parse_id(t_scene *scene, char *str);
void	parser(char *file_name, t_scene *scene);
void	fill_scene_null(t_scene *scene);
t_color	fill_color_null(t_color color);
int		num_length(int num);
int		correct_input(char *str);
double	ft_atod(char *str);
int		double_length(char *str);
t_vec	get_cordinates(char **str);
t_color	get_color(char **str);
int		check_color(t_color color);
int		check_norm_vec(t_vec vec);
int		check_name(char *str);
int		check_map_correct(t_scene *scene);
int		check_bmp(char *str, char *bmp);
int		check_scene_existance(t_mlx	*mlx);
int		check_input(int argc, char *argv[]);

#endif