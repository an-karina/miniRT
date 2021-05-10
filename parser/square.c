/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:52:29 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/11 01:06:25 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_square(t_scene *scene, char *str)
{
	t_square	*square;
	t_object	*object;

	str += 2;
	ft_is_space(&str);
	if (!correct_input(str))
		return (fill_scene_null(scene));
	if (!(square = (t_square *)malloc(sizeof(t_square))))
		return (fill_scene_null(scene));
	square->center.existance = EXISTS;
	square->center = get_cordinates(&str);
	if (square->center.existance != EXISTS)
		return (fill_scene_null(scene));
	if (!correct_input(str))
		return (fill_scene_null(scene));
	square->norm.existance = EXISTS;
	square->norm = get_cordinates(&str);
	if (square->norm.existance != EXISTS)
		return (fill_scene_null(scene));
	if (check_norm_vec(square->norm))
		return (fill_scene_null(scene));
	if (!correct_input(str))
		return (fill_scene_null(scene));
	square->size = ft_atod(str);
	str += double_length(str);
	ft_is_space(&str);
	if (!(object = (t_object *)malloc(sizeof(t_object))))
		return (fill_scene_null(scene));
	object->color.existance = EXISTS;
	object->color = get_color(&str);
	if (object->color.existance != EXISTS)
		return (fill_scene_null(scene));
	ft_is_space(&str);
	if (*str != '\0')
		return (fill_scene_null(scene));
	object->shape = square;
	object->intersection = &solve_equation_square;
	object->norm = &normal_square;
	if (scene->objects == NULL)
		scene->objects = ft_lstnew(object);
	else
		ft_lstadd_front(&(scene->objects), ft_lstnew(object));
	scene->existance = EXISTS;
	return ;
}
