/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:19:07 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/23 16:52:51 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
	if (scene->cameras != NULL)
		ft_free_list(&(scene->cameras));
	if (scene->light != NULL)
		ft_free_list(&(scene->light));
	if (scene->objects != NULL)
		ft_free_list(&(scene->objects));
	return ;
}

void	parse_id(t_scene *scene, char *str)
{
	ft_is_space(&str);
	if (*str == '\0')
		return ;
	if (*str == 'R')
		parse_resolution(scene, str);
	else if (*str == 'A')
		parse_ambient(scene, str);
	else if (*str == 'c' && *(str + 1) != 'y')
		parse_camera(scene, str);
	else if (*str == 'l')
		parse_light(scene, str);
	else if (*str == 's' && *(str + 1) == 'p')
		parse_sphere(scene, str);
	else if (*str == 'p' && *(str + 1) == 'l')
		parse_plane(scene, str);
	else if (*str == 's' && *(str + 1) == 'q')
		parse_square(scene, str);
	else if (*str == 'c' && *(str + 1) == 'y')
		parse_cylinder(scene, str);
	else if (*str == 't' && *(str + 1) == 'r')
		parse_triangle(scene, str);
	else
		scene->existance = DOES_NOT_EXIST;
	return ;
}

int	parse_line(t_scene *scene, char **str)
{
	parse_id(scene, *str);
	if (scene->existance != EXISTS)
	{
		free(*str);
		return (0);
	}
	free(*str);
	return (1);
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
		if (*str == '#')
		{
			free(str);
			continue ;
		}
		if (check_if_only_new_line(str))
		{
			free(str);
			continue ;
		}
		if (!parse_line(scene, &str))
			return (fill_scene_null(scene));
	}
	if (!parse_line(scene, &str))
		return (fill_scene_null(scene));
	return ;
}
