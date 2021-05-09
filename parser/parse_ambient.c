/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:36:21 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/08 18:47:22 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

double	ft_atod(char *str)
{
	double 	num;
	double 	num_after_dot;
	double	pow_num;
	int 	length;

	num = 0.0;
	num = (double)ft_atoi(str);
	str = str + num_length(num);
	if (*str != '.')
		return (num);
	str++;
	num_after_dot = (double)ft_atoi(str);
	length = num_length(num_after_dot);
	pow_num = pow(10, length);
	num_after_dot = num_after_dot / pow_num;
	num = num + num_after_dot;
	return (num);
}

int	double_length(char *str)
{
	int length;

	length = 0;
	if (*str == '-' || *str == '+')
	{
		str++;
		length++;
	}
	while (*str <= '9' && *str >= '0')
	{
		length++;
		str++;
	}
	if (*str != '.')
		return (length);
	str++;
	length++;
	while (*str <= '9' && *str >= '0')
	{
		length++;
		str++;
	}
	return (length);
}

int	check_color(t_color color)
{
	if (color.r < 0 || color.g < 0 || color.b < 0)
		return (1);
	if (color.r > 255 || color.g > 255 || color.b > 255)
		return (1);
	return (0);
}

t_scene read_color(t_scene *scene, char **str)
{
	if (!correct_input(*str))
		return (fill_scene_null(*scene));
	scene->amb.color.r = ft_atoi(*str);
	*str += num_length(scene->amb.color.r);
	ft_is_space(str);
	if (**str != ',')
		return (fill_scene_null(*scene));
	(*str)++;
	ft_is_space(str);
	if (!correct_input(*str))
		return (fill_scene_null(*scene));
	scene->amb.color.g = ft_atoi(*str);
	*str += num_length(scene->amb.color.g);
	ft_is_space(str);
	if (**str != ',')
		return (fill_scene_null(*scene));
	(*str)++;
	ft_is_space(str);
	if (!correct_input(*str))
		return (fill_scene_null(*scene));
	scene->amb.color.b = ft_atoi(*str);
	*str += num_length(scene->amb.color.g);
	ft_is_space(str);
	if (check_color(scene->amb.color))
		return(fill_scene_null(*scene));
	return (*scene);
}

t_scene	parse_ambient(t_scene scene, char *str)
{
	t_color	color;
	
	if (scene.amb.existance == EXISTS)
		return (fill_scene_null(scene));
	str++;
	ft_is_space(&str);
	if (!correct_input(str))
		return (fill_scene_null(scene));
	scene.amb.intensity = ft_atod(str);
	if (scene.amb.intensity < 0.0 || scene.amb.intensity > 1.0)
		return (fill_scene_null(scene));
	str = str + double_length(str);
	ft_is_space(&str);
	scene.existance = EXISTS;
	scene = read_color(&scene, &str);
	if (scene.existance != EXISTS)
		return (scene);
	ft_is_space(&str);
	if (*str != '\0')
		return (fill_scene_null(scene));
	scene.amb.existance = EXISTS;
	scene.existance = EXISTS;
	return (scene);
}
