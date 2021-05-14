/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:44:25 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/14 20:04:32 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	get_sphere(t_sphere *sphere, char **str)
{
	if (!correct_input(*str))
		return (1);
	sphere->center.existance = EXISTS;
	sphere->center = get_cordinates(str);
	if (sphere->center.existance != EXISTS)
		return (1);
	ft_is_space(str);
	if (!correct_input(*str))
		return (1);
	sphere->r = (ft_atod(*str)) / 2;
	*str += double_length(*str);
	ft_is_space(str);
	return (0);
}

int	get_object_sphere(t_object *object, char **str, t_sphere *sphere)
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
	object->shape = sphere;
	object->intersection = &solve_equation_sphere;
	object->norm = &normal_sphere;
	return (0);
}

void	parse_sphere(t_scene *scene, char *str)
{
	t_sphere	*sphere;
	t_object	*object;

	str +=2;
	ft_is_space(&str);
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		return (fill_scene_null(scene));
	if (get_sphere(sphere, &str))
		return (fill_scene_null(scene));
	object = (t_object *)malloc(sizeof(t_object));
	if (!object)
		return (fill_scene_null(scene));
	if (get_object_sphere(object, &str, sphere))
		return (fill_scene_null(scene));
	ft_lstadd_front(&(scene->objects), ft_lstnew(object));
	scene->existance = EXISTS;
	return ;
}
