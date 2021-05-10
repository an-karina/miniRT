/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:44:25 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/11 00:40:32 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_sphere(t_scene *scene, char *str)
{
	t_sphere	*sphere;
	t_object	*object;
	
	str +=2;
	ft_is_space(&str);
	if (!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		return (fill_scene_null(scene));
	if (!correct_input(str))
		return (fill_scene_null(scene));
	sphere->center.existance = EXISTS;
	sphere->center = get_cordinates(&str);
	if (sphere->center.existance != EXISTS)
		return (fill_scene_null(scene));
	ft_is_space(&str);
	if (!correct_input(str))
		return (fill_scene_null(scene));
	sphere->r = (ft_atod(str)) / 2;
	str += double_length(str);
	ft_is_space(&str);
	if (!(object = (t_object *)malloc(sizeof(t_object))))
		return (fill_scene_null(scene));
	if (!correct_input(str))
		return (fill_scene_null(scene));
	object->color.existance = EXISTS;
	object->color = get_color(&str);
	if (object->color.existance != EXISTS)
		return (fill_scene_null(scene));
	ft_is_space(&str);
	if (*str != '\0')
		return (fill_scene_null(scene));
	object->shape = sphere;
	object->intersection = &solve_equation_sphere;
	object->norm = &normal_sphere;
	if (scene->objects == NULL)
		scene->objects = ft_lstnew(object);
	else
		ft_lstadd_front(&(scene->objects), ft_lstnew(object));
	scene->existance = EXISTS;
	return ;
}
