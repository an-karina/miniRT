/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:48:05 by jhleena           #+#    #+#             */
/*   Updated: 2021/03/19 19:20:29 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_scene
{
	t_list		objects;
	t_list		cameras;
	t_list		lights;
}				t_scene;

int				ray_trace(t_ray ray, t_scene scene);