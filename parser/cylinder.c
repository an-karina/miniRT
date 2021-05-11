/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 08:44:49 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/11 09:23:06 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_cylinder(t_scene *scene, char *str)
{
	t_object	*object;
	t_cylinder	*cylinder;

	str += 2;
	ft_is_space(&str);
	if (!correct_input(str))
		return (fill_scene_null(scene));
	if (!(cylinder = (t_cylinder *)malloc(sizeof(t_cylinder))))
		return (fill_scene_null(scene));
	cylinder->center.existance = EXISTS;
	cylinder->center = (t_point)get_cordinates(&str);
	if (cylinder->center.existance != EXISTS)
		return (fill_scene_null(scene));

	if (!correct_input(str))
		return (fill_scene_null(scene));
	cylinder->norm.existance = EXISTS;
	cylinder->norm = get_cordinates(&str);
	if (cylinder->norm.existance != EXISTS)
		return (fill_scene_null(scene));
	
	if (!correct_input(str))
		return (fill_scene_null(scene));
	cylinder->d = ft_atod(str);
	str += double_length(str);
	ft_is_space(&str);

	if (!correct_input(str))
		return (fill_scene_null(scene));
	cylinder->height = ft_atod(str);
	str += double_length(str);
	ft_is_space(&str);

	if (!correct_input(str))
		return (fill_scene_null(scene));
	if (!(object = (t_object *)malloc(sizeof(t_object))))
		return (fill_scene_null(scene));
	object->color.existance = EXISTS;
	object->color = get_color(&str);
	if (object->color.existance != EXISTS)
		return (fill_scene_null(scene));
	object->intersection = &solve_equation_cylinder;
	object->norm = &normal_cylinder;
	object->shape = cylinder;
	if (scene->objects == NULL)
		scene->objects = ft_lstnew(object);
	else
		ft_lstadd_front(&(scene->objects), ft_lstnew(object));
	scene->existance = EXISTS;
	return ;
}