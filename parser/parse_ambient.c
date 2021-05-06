/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:36:21 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/06 17:35:56 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

double	ft_atod(char *str)
{
	double num;

	num = 0.0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (*str != '.' && *str != ' ')
		return (0.0)
}

t_scene	parse_ambient(t_scene scene, char *str)
{
	if (scene.amb.existance == EXISTS)
		return (fill_scene_null(scene));
	str++;
	str = ft_is_space(str);
	if (!correct_input(str))
		return (fill_scene_null(scene));
	scene.amb.intensity = ft_atod(scene, str);
	return (scene);
}
