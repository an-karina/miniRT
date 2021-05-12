/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:43:19 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/12 09:15:57 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_norm_vec(t_vec vec)
{
	if (vec.x < -1.0 || vec.y < -1.0 || vec.z < -1.0)
		return (1);
	if (vec.x > 1.0 || vec.y > 1.0 || vec.z > 1.0)
		return (1);
	return (0);
}

double	one_coordinate(t_vec *vec, char **str)
{
	double	num;

	if (!correct_input(*str))
	{
		vec->existance = DOES_NOT_EXIST;
		return (0.0);
	}
	num = ft_atod(*str);
	*str += double_length(*str);
	ft_is_space(str);
	if (**str != ',')
	{
		vec->existance = DOES_NOT_EXIST;
		return (0.0);
	}
	(*str)++;
	ft_is_space(str);
	return (num);
}

t_vec	get_cordinates(char **str)
{
	t_vec	vec;

	vec.existance = EXISTS;
	vec.x = one_coordinate(&vec, str);
	if (vec.existance != EXISTS)
		return (vec);
	vec.y = one_coordinate(&vec, str);
	if (vec.existance != EXISTS)
		return (vec);
	if (!correct_input(*str))
	{
		vec.existance = DOES_NOT_EXIST;
		return (vec);
	}
	vec.z = ft_atod(*str);
	*str += double_length(*str);
	ft_is_space(str);
	return (vec);
}

int	get_camera(t_camera *camera, char **str)
{
	if (!correct_input(*str))
		return (1);
	camera->position = (t_point)get_cordinates(str);
	if (camera->position.existance != EXISTS)
		return (1);
	if (!correct_input(*str))
		return (1);
	camera->view = get_cordinates(str);
	if (camera->view.existance != EXISTS)
		return (1);
	if (check_norm_vec(camera->view))
		return (1);
	if (!correct_input(*str))
		return (1);
	camera->fov = ft_atod(*str);
	*str += double_length(*str);
	ft_is_space(str);
	return (0);
}

void	parse_camera(t_scene *scene, char *str)
{
	t_camera	*camera;

	++str;
	ft_is_space(&str);
	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		return (fill_scene_null(scene));
	if (get_camera(camera, &str))
		return (fill_scene_null(scene));
	if (*str != '\0')
		return (fill_scene_null(scene));
	ft_lstadd_front(&(scene->cameras), ft_lstnew(camera));
	scene->existance = EXISTS;
}
