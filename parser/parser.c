/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:19:07 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/10 13:37:47 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

char	**ft_is_space(char **str)
{
	while (**str == ' '|| (**str == '\t') || (**str == '\r') ||
			(**str == '\v') || (**str == '\n') || (**str == '\f'))
		(*str)++;
	return (str);
}

int	check_if_only_new_line(char *str)
{
	if (*str != '\0')
		return (0);
	return (1);
}

void	fill_scene_null(t_scene *scene)
{

	scene->existance = DOES_NOT_EXIST;
	scene->resolution.existance = DOES_NOT_EXIST;
	scene->amb.existance = DOES_NOT_EXIST;
	scene->cameras = NULL;
	scene->light = NULL;
	scene->objects = NULL;
	return ;
}

void	parse_id(t_scene *scene, char *str)
{
	int a;
	
	ft_is_space(&str);
	if (*str == '\0')
		return ;
	if (*str == 'R')
		parse_resolution(scene, str);
	else if (*str == 'A')
		parse_ambient(scene, str);
	else if (*str == 'c')
		parse_camera(scene, str);
	else if (*str == 'l')
		parse_light(scene, str);
	/*else if (*str == 's' && *(str + 1) == 'p')
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
		scene->existance = DOES_NOT_EXIST;
	a = 0;
	a++;
		return ;
}

void	parser(char *file_name, t_scene *scene)
{
	int		fd;
	char	*str;

	fill_scene_null(scene);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return ;
	while (get_next_line(fd, &str) > 0)
	{
		if (check_if_only_new_line(str))
			continue ;
		parse_id(scene, str);
		if (scene->existance != EXISTS)
			return ;
	}
	parse_id(scene, str);
	if (scene->existance != EXISTS)
		return ;
	return ;
}
