/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 08:44:42 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/21 09:48:59 by jhleena          ###   ########.fr       */
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

int		get_object_triangle(t_object *object, char **str, t_triangle *triangle)
{
	object->color.existance = EXISTS;
	object->color = get_color(str);
	if (object->color.existance != EXISTS)
		return (1);
	ft_is_space(str);
	if (**str != '\0')
		return (1);
	object->intersection = &solve_equation_triangle;
	object->norm = &normal_triangle;
	object->shape = triangle;
	return (0);
}

void	get_norm(t_triangle *triangle)
{
	t_vec	side1;
	t_vec	side2;

	side1 = vec_sub(triangle->second_p, triangle->first_p);
	side2 = vec_sub(triangle->third_p, triangle->first_p);
	triangle->norm = vec_cross(side2, side1);
	triangle->norm =  vec_norm(triangle->norm);
}

//check_exictance_tr();

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
	get_norm(triangle);
	triangle->edge_fs = vec_sub(triangle->second_p, triangle->first_p);
	triangle->edge_ft = vec_sub(triangle->third_p, triangle->first_p);
	//triangle->edge_st = vec_sub(triangle->third_p, triangle->second_p);
	//check_exictance_tr();
	object = (t_object *)malloc(sizeof(t_object));
	if (object == NULL)
		return (fill_scene_null(scene));
	if (get_object_triangle(object, &str, triangle))
		return (fill_scene_null(scene));
	ft_lstadd_front(&(scene->objects), ft_lstnew(object));
	scene->existance = EXISTS;
	return ;
}
