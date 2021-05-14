/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:52:29 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/14 20:02:38 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	get_square(t_square *square, char **str)
{
	if (!correct_input(*str))
		return (1);
	square->center.existance = EXISTS;
	square->center = get_cordinates(str);
	if (square->center.existance != EXISTS)
		return (1);
	if (!correct_input(*str))
		return (1);
	square->norm.existance = EXISTS;
	square->norm = get_cordinates(str);
	if (square->norm.existance != EXISTS)
		return (1);
	if (check_norm_vec(square->norm))
		return (1);
	if (!correct_input(*str))
		return (1);
	square->size = ft_atod(*str);
	*str += double_length(*str);
	ft_is_space(str);
	return (0);
}

int	get_object_square(t_object *object, char **str, t_square *square)
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
	object->shape = square;
	object->intersection = &solve_equation_square;
	object->norm = &normal_square;
	return (0);
}

void	parse_square(t_scene *scene, char *str)
{
	t_square	*square;
	t_object	*object;

	str += 2;
	ft_is_space(&str);
	square = (t_square *)malloc(sizeof(t_square));
	if (!square)
		return (fill_scene_null(scene));
	if (get_square(square, &str))
		return (fill_scene_null(scene));
	object = (t_object *)malloc(sizeof(t_object));
	if (!object)
		return (fill_scene_null(scene));
	if (get_object_square(object, &str, square))
		return (fill_scene_null(scene));
	ft_lstadd_front(&(scene->objects), ft_lstnew(object));
	scene->existance = EXISTS;
	return ;
}
