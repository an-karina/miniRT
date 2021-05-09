/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:21:23 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/08 18:49:59 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	correct_input(char *str)
{

	if (*str == '-' || *str == '+')
		++str;
	if (*str <= '9' && *str >= '0')
		return (1);
	return (0);
}

int	num_length(int num)
{
	int	length;
	long long num_2;

	length = 0;
	num_2 = (long long)num;
	if (num_2 == 0)
		length++;
	if (num_2< 0)
	{
		length++;
		num_2 = num_2 * (-1);
	}
	while (num_2 > 0)
	{
		length++;
		num_2 = num_2 / 10;
	}
	return (length);
}

int		check_resolution(t_wind resolution)
{
	if (resolution.width > 2560 || resolution.height > 1600)
		return (1);
	if (resolution.width < 1 || resolution.height < 1)
		return (1);
	return (0);
}

t_scene	parse_resolution(t_scene scene, char *str)
{
	if (scene.resolution.existance == EXISTS)
		return (fill_scene_null(scene));
	str++;
	ft_is_space(&str);
	if (!correct_input(str))
		return (fill_scene_null(scene));
	scene.resolution.width = ft_atoi(str);
	str += num_length(scene.resolution.width);
	ft_is_space(&str);
	if (!correct_input(str))
		return (fill_scene_null(scene));
	scene.resolution.height = ft_atoi(str);
	str += num_length(scene.resolution.height);
	ft_is_space(&str);
	if (check_resolution(scene.resolution))
		return (fill_scene_null(scene));
	if (*str != '\0')
		return (fill_scene_null(scene));
	scene.resolution.existance = EXISTS;
	scene.existance = EXISTS;
	return (scene);
}
