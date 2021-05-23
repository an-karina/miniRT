/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 23:46:27 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/23 15:59:37 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "../libft/libft.h"	
#include "../mlx/mlx.h"
#include <stdio.h>
#include "parser.h"

int	check_name(char *str)
{
	int	length;

	length = ft_strlen(str);
	return (ft_strncmp(str + length - 3, ".rt", 3));
}

int	check_map_correct(t_scene *scene)
{
	if (scene->resolution.existance != EXISTS)
		return (1);
	if (scene->amb.existance != EXISTS)
		return (1);
	if (scene->cameras == NULL)
		return (1);
	if (scene->objects == NULL)
		return (1);
	return (0);
}

int	check_screen(char *str, char *bmp)
{
	while (*str)
	{
		if (*str != *bmp)
			return (1);
		str++;
		bmp++;
	}
	return (0);
}

int	check_scene_existance(t_mlx	*mlx)
{
	if ((mlx->scene)->existance == DOES_NOT_EXIST)
	{
		fill_scene_null(mlx->scene);
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	check_input(int argc, char *argv[])
{
	if (argc > 3 || argc < 2 || check_name(argv[1])
		|| (argc == 3 && check_screen(argv[2], "--save")))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
