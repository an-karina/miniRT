/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 08:44:49 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/12 08:35:53 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	get_center_norm(t_cylinder *cylinder, char **str)
{
	if (!correct_input(*str))
		return (1);
	cylinder->center.existance = EXISTS;
	cylinder->center = (t_point)get_cordinates(str);
	if (cylinder->center.existance != EXISTS)
		return (1);
	if (!correct_input(*str))
		return (1);
	cylinder->norm.existance = EXISTS;
	cylinder->norm = get_cordinates(str);
	if (cylinder->norm.existance != EXISTS)
		return (1);
	if (check_norm_vec(cylinder->norm))
		return (1);
	return (0);
}

int	get_diameter_height(t_cylinder *cylinder, char **str)
{
	if (!correct_input(*str))
		return (1);
	cylinder->d = ft_atod(*str);
	*str += double_length(*str);
	ft_is_space(str);
	if (!correct_input(*str))
		return (1);
	cylinder->height = ft_atod(*str);
	*str += double_length(*str);
	ft_is_space(str);
	return (0);
}

int	create_object(t_object **object, char **str, t_cylinder *cylinder)
{
	*object = (t_object *)malloc(sizeof(t_object));
	if (!*object)
		return (1);
	(*object)->color.existance = EXISTS;
	(*object)->color = get_color(str);
	if ((*object)->color.existance != EXISTS)
		return (1);
	(*object)->intersection = &solve_equation_cylinder;
	(*object)->norm = &normal_cylinder;
	(*object)->shape = cylinder;
	return (0);
}

void	parse_cylinder(t_scene *scene, char *str)
{
	t_object	*object;
	t_cylinder	*cylinder;

	str += 2;
	ft_is_space(&str);
	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cylinder)
		return (fill_scene_null(scene));
	if (get_center_norm(cylinder, &str))
		return (fill_scene_null(scene));
	if (get_diameter_height(cylinder, &str))
		return (fill_scene_null(scene));
	if (!correct_input(str))
		return (fill_scene_null(scene));
	if (create_object(&object, &str, cylinder))
		return (fill_scene_null(scene));
	ft_lstadd_front(&(scene->objects), ft_lstnew(object));
	scene->existance = EXISTS;
	return ;
}
