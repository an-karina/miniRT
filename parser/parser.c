/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:19:07 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/06 20:28:00 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

char	*ft_is_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

int	check_if_only_new_line(char *str)
{
	if (*str != '\0')
		return (0);
	return (1);
}

t_scene	fill_scene_null(t_scene scene)
{

	scene.existance = DOES_NOT_EXIST;
	scene.resolution.existance = DOES_NOT_EXIST;
	scene.amb.existance = DOES_NOT_EXIST;
	return (scene);
}

t_scene	parse_id(t_scene scene, char *str)
{
	str = ft_is_space(str);
	if (*str == 'R')
		scene = parse_resolution(scene, str);
	else if (*str == 'A')
		scene = parse_ambient(scene, str);
	/*else if (*str == 'c')
		parse_camera();
	else if (*str == 'l')
		parse_light();
	else if (*str == 's' && *(str + 1) == 'p')
		parse_sphere();
	else if (*str == 'p' && *(str + 1) == 'l')
		parse_plane();
	else if (*str == 's' && *(str + 1) == 'q')
		parse_square();
	else if (*str == 'c' && *(str + 1) == 'y')
		parse_cylinder();
	else if (*str == 't' && *(str + 1) == 'r')
		parse_triangle();*/
	else 
		scene.existance = DOES_NOT_EXIST;
		return (scene);
}

t_scene	parser(char *file_name)
{
	int		fd;
	t_scene	scene;
	char	*str;

	scene = fill_scene_null(scene);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (scene);
	while (get_next_line(fd, &str) > 0)
	{
		if (check_if_only_new_line(str))
			continue ;
		scene = parse_id(scene, str);
		if (scene.existance != EXISTS)
			return (scene);
	}
		scene = parse_id(scene, str);
		if (scene.existance != EXISTS)
			return (scene);
	return (scene);
}
