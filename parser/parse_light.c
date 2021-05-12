/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:14:04 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/12 09:20:25 by jhleena          ###   ########.fr       */
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
	t_color	color;

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
	if (check_color(color))
		return (fill_color_null(color));
	return (color);
}

int	get_light(t_light *light, char **str)
{
	if (!correct_input(*str))
		return (1);
	light->center = get_cordinates(str);
	if (light->center.existance != EXISTS)
		return (1);
	if (!correct_input(*str))
		return (1);
	light->intensity = ft_atod(*str);
	if (light->intensity < 0 || light->intensity > 1)
		return (1);
	*str += double_length(*str);
	ft_is_space(str);
	if (!correct_input(*str))
		return (1);
	light->color.existance = EXISTS;
	light->color = get_color(str);
	if (light->color.existance != EXISTS)
		return (1);
	ft_is_space(str);
	return (0);
}

void	parse_light(t_scene *scene, char *str)
{
	t_light	*light;

	str++;
	ft_is_space(&str);
	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		return (fill_scene_null(scene));
	if (get_light(light, &str))
		return (fill_scene_null(scene));
	if (*str != '\0')
		return (fill_scene_null(scene));
	ft_lstadd_front(&(scene->light), ft_lstnew(light));
	scene->existance = EXISTS;
	return ;
}
