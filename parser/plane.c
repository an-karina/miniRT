/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:01:47 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/12 09:26:03 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_plane(t_scene *scene, char *str)
{
	t_plane		*plane;
	t_object	*object;

	str += 2;
	ft_is_space(&str);
	if (!(plane = (t_plane *)malloc(sizeof(t_plane))))
		return (fill_scene_null(scene));
	if (!correct_input(str))
		return (fill_scene_null(scene));
	plane->p.existance = EXISTS;
	plane->p = get_cordinates(&str);
	if (plane->p.existance != EXISTS)
		return (fill_scene_null(scene));
	if (!correct_input(str))
		return (fill_scene_null(scene));
	plane->norm.existance = EXISTS;
	plane->norm = (t_vec)get_cordinates(&str);
	if (plane->norm.existance != EXISTS)
		return (fill_scene_null(scene));
	if (check_norm_vec(plane->norm))
		return (fill_scene_null(scene));
	if (!correct_input(str))
		return (fill_scene_null(scene));
	if (!(object = (t_object *)malloc(sizeof(t_object))))
		return (fill_scene_null(scene));
	object->color.existance = EXISTS;
	object->color = get_color(&str);
	if (object->color.existance != EXISTS)
		return (fill_scene_null(scene));
	if (*str != '\0')
		return (fill_scene_null(scene));
	object->shape = plane;
	object->intersection = &solve_equation_plane;
	object->norm = &normal_plane;
	ft_lstadd_front(&(scene->objects), ft_lstnew(object));
	scene->existance = EXISTS;
	return ;
}
