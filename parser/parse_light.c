/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:14:04 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/10 15:48:53 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_color	fill_color_null(t_color color)
{
	color.existance = DOES_NOT_EXIST;
	return (color);
}

t_color	get_color(char **str)
{
	t_color color;

	color.existance = EXISTS;
	if (!correct_input(*str))
		return (fill_color_null(color));
	color.r = ft_atoi(*str);
	*str += num_length(color.r);
	ft_is_space(str);
	if (**str != ',')
		return (fill_color_null(color));
	(*str)++;
	ft_is_space(str);
	if (!correct_input(*str))
		return (fill_color_null(color));
	color.g = ft_atoi(*str);
	*str += num_length(color.g);
	ft_is_space(str);
	if (**str != ',')
		return (fill_color_null(color));
	(*str)++;
	ft_is_space(str);
	if (!correct_input(*str))
		return (fill_color_null(color));
	color.b = ft_atoi(*str);
	*str += num_length(color.b);
	ft_is_space(str);
	if (check_color(color))
		return(fill_color_null(color));
	return (color);
}

void	parse_light(t_scene *scene, char *str)
{
	t_light	*light;
	
	if (!(light = (t_light *)malloc(sizeof(t_light))))
		return (fill_scene_null(scene));
	str++;
	ft_is_space(&str);
	light->existance = EXISTS;
	if (!correct_input(str))
		return (fill_scene_null(scene));
	light->center = get_cordinates(&str);
	if (light->center.existance != EXISTS)
 		return (fill_scene_null(scene));
	if (!correct_input(str))
		return (fill_scene_null(scene));
	light->intensity = ft_atod(str);
	str += double_length(str);
	ft_is_space(&str);
	if (!correct_input(str))
		return (fill_scene_null(scene));
	light->color.existance = EXISTS;
	light->color = get_color(&str);
	if (light->color.existance != EXISTS)
		return (fill_scene_null(scene));
	ft_is_space(&str);
	if (*str != '\0')
 		return (fill_scene_null(scene));
	if (scene->light == NULL)
 		scene->light = ft_lstnew(light);
 	else
 		ft_lstadd_front(&(scene->light), ft_lstnew(light));
	scene->existance = EXISTS;
	return ;
}
