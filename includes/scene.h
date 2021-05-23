/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:48:05 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/23 00:39:51 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "camera.h"
# include "object.h"
# include "light.h"
# include "../libft/libft.h"

typedef struct s_scene
{
	t_list			*objects;
	t_list			*cameras;
	t_list			*light;
	t_ambient		amb;
	t_wind			resolution;
	enum e_exist	existance;
}				t_scene;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_list	*first_camera;
	t_scene	*scene;
	t_data	img;
	int		current_cam;
}				t_mlx;

t_ray			get_ray(int x, int y, t_camera camera, t_wind winndow);
t_color			ray_trace(t_ray ray, t_scene scene);
t_color			lightnig(double t, t_ray ray, t_object *obj_max, t_scene scene);
t_vec			normal_sphere(double t, t_ray ray, t_object object);
t_vec			normal_plane(double t, t_ray ray, t_object object);
t_vec			intensity(t_color color, double intensity);
t_point			calc_point(t_ray ray, double t);
void			bmp_file(t_data img, t_scene *scene);
int				key_hook(int keycode, t_mlx *mlx);
void			my_mlx_key_hook(t_mlx *mlx);
void			draw_scene(t_mlx *mlx);

#endif
