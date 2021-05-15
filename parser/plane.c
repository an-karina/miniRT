/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:01:47 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/15 17:41:01 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	create_object_plane(t_object *object, char **str, t_plane *plane)
{
	if (!correct_input(*str))
		return (1);
	object->color.existance = EXISTS;
	object->color = get_color(str);
	if (object->color.existance != EXISTS)
		return (1);
	ft_is_space(str);
	if (**str != '\0')
		return (1);
	object->shape = plane;
	object->intersection = &solve_equation_plane;
	object->norm = &normal_plane;
	return (0);
}

int	get_plane(t_plane *plane, char **str)
{
	if (!correct_input(*str))
		return (1);
	plane->p.existance = EXISTS;
	plane->p = get_cordinates(str);
	if (plane->p.existance != EXISTS)
		return (1);
	if (!correct_input(*str))
		return (1);
	plane->norm.existance = EXISTS;
	plane->norm = (t_vec)get_cordinates(str);
	if (plane->norm.existance != EXISTS)
		return (1);
	if (check_norm_vec(plane->norm))
		return (1);
	return (0);
}

void	parse_plane(t_scene *scene, char *str)
{
	t_plane		*plane;
	t_object	*object;

	str += 2;
	ft_is_space(&str);
	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		return (fill_scene_null(scene));
	if (get_plane(plane, &str))
		return (fill_scene_null(scene));
	object = (t_object *)malloc(sizeof(t_object));
	if (!object)
		return (fill_scene_null(scene));
	if (create_object_plane(object, &str, plane))
		return (fill_scene_null(scene));
	ft_lstadd_front(&(scene->objects), ft_lstnew(object));
	scene->existance = EXISTS;
	return ;
}
