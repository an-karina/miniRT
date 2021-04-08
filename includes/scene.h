/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:48:05 by jhleena           #+#    #+#             */
/*   Updated: 2021/04/08 15:19:12 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "camera.h"
# include "object.h"
# include "../libft/libft.h"

typedef struct	s_scene
{
	t_list		*objects;
	t_list		*cameras;
}				t_scene;

t_color			ray_trace(t_ray ray, t_scene scene);

#endif
