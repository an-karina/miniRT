/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:36:21 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/07 00:16:37 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

double	ft_atod(char *str)
{
	double num;
	double num_after_dot;
	int length;

	num = 0.0;
	num = (double)ft_atoi(str);
	str = str + num_length(num);
	if (*str != '.')
		return (num);
	str++;
	num_after_dot = (double)ft_atoi(str);
	length = num_length(num_after_dot);
	num_after_dot = num_after_dot / pow(10, length);
	num = num + num_after_dot;
	return (num);
}

t_scene	parse_ambient(t_scene scene, char *str)
{
	if (scene.amb.existance == EXISTS)
		return (fill_scene_null(scene));
	str++;
	str = ft_is_space(str);
	if (!correct_input(str))
		return (fill_scene_null(scene));
	scene.amb.intensity = ft_atod(str);
	return (scene);
}
