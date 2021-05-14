/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 08:44:42 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/14 20:07:37 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	get_side(t_triangle *triangle, char **str)
{
	if (!correct_input(*str))
		return (1);
	triangle->first_p.existance = EXISTS;
	triangle->first_p = get_cordinates(str);
	if (triangle->first_p.existance != EXISTS)
		return (1);
	ft_is_space(str);
	if (!correct_input(*str))
		return (1);
	triangle->second_p.existance = EXISTS;
	triangle->second_p = get_cordinates(str);
	if (triangle->second_p.existance != EXISTS)
		return (1);
	ft_is_space(str);
	if (!correct_input(*str))
		return (1);
	triangle->third_p.existance = EXISTS;
	triangle->third_p = get_cordinates(str);
	if (triangle->third_p.existance != EXISTS)
		return (1);
	ft_is_space(str);
	return (0);
}

void	parse_triangle(t_scene *scene, char *str)
{
	t_object	*object;
	t_triangle	*triangle;

	str += 2;
	ft_is_space(&str);
	triangle = (t_triangle *)malloc(sizeof(t_triangle));
	if (triangle == NULL)
		return (fill_scene_null(scene));
	if (get_side(triangle, &str))
		return (fill_scene_null(scene));
	if (!correct_input(str))
		return (fill_scene_null(scene));
	object = (t_object *)malloc(sizeof(t_object));
	if (object == NULL)
		return (fill_scene_null(scene));
	object->color.existance = EXISTS;
	object->color = get_color(&str);
	if (object->color.existance != EXISTS)
		return (fill_scene_null(scene));
	object->intersection = &solve_equation_triangle;
	object->norm = &normal_triangle;
	object->shape = triangle;
	ft_lstadd_front(&(scene->objects), ft_lstnew(object));
	scene->existance = EXISTS;
	return ;
}
