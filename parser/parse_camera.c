/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:43:19 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/09 14:59:10 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_norm_vec(t_vec vec)
{
	if (vec.x < 0.0 || vec.y < 0.0 || vec.z < 0.0)
		return (1);
	if (vec.x > 1.0 || vec.y > 1.0 || vec.z > 1.0)
		return (1);
	return (0);
}

double	one_coordinate(t_vec *vec, char **str)
{
	double num;
	 
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
	t_vec vec;

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

// t_scene	parse_camera(t_scene scene, char *str)
// {
// 	t_camera camera;

// 	str++;
// 	ft_is_space(&str);
// 	camera.existance = EXISTS;
// 	camera.position = (t_point)get_cordinates(&str);
// 	if (camera.position.existance != EXISTS)
// 		return (fill_scene_null(scene));
// 	camera.view.existance = EXISTS;
// 	camera.view = get_cordinates(&str);
// 	if (camera.view.existance != EXISTS)
// 		return (fill_scene_null(scene));
// 	if (check_norm_vec(camera.view))
// 		return (fill_scene_null(scene));
// 	if (!correct_input(str))
// 		return (fill_scene_null(scene));
// 	camera.fov = ft_atod(str);
// 	str += double_length(str);
// 	ft_is_space(&str);
// 	if (*str != '\0')
// 		return (fill_scene_null(scene));
// 	if (scene.cameras == NULL)
// 		scene.cameras = ft_lstnew(&camera);
// 	else
// 		ft_lstadd_front(&(scene.cameras), ft_lstnew(&camera));
// 	scene.existance = EXISTS;
// 	return (scene);
// }

t_scene parse_camera(t_scene scene, char *str)
{
 	t_camera *camera;

	if (!(camera = (t_camera *)malloc(sizeof(t_camera))))
  		return (fill_scene_null(scene));
 	++str;
 	ft_is_space(&str);
 	camera->existance = EXISTS;
 	camera->position = (t_point)get_cordinates(&str);
 	if (camera->position.existance != EXISTS)
 		return (fill_scene_null(scene));
 	camera->view.existance = EXISTS;
 	camera->view = get_cordinates(&str);
 	if (camera->view.existance != EXISTS)
 		return (fill_scene_null(scene));
 	if (check_norm_vec(camera->view))
 		return (fill_scene_null(scene));
 	if (!correct_input(str))
 		return (fill_scene_null(scene));
 	camera->fov = ft_atod(str);
 	str += double_length(str);
 	ft_is_space(&str);
 	if (*str != '\0')
 	 return (fill_scene_null(scene));
 	if (scene.cameras == NULL)
 	 scene.cameras = ft_lstnew(camera);
 	else
 	 ft_lstadd_front(&(scene.cameras), ft_lstnew(camera));
 	return (scene.existance = EXISTS, scene);
}