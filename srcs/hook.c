/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:59:14 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/22 20:21:04 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_struct.h"
#include "scene.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	int count;
	
	if (keycode == 48)
	{
		count = ft_lstsize(mlx->scene->cameras);
	}
	return (0);
}