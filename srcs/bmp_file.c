/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:07:12 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/21 20:32:16 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    bmp_file(t_data img, t_scene *scene)
{
    int fd;
    int size;
    int pl;
    int deep_cl;

    size = 54 + 4 * scene->resolution.width * scene->resolution.height;
    pl = 1;
    deep_cl = 32;
    fd = open("screenshot.bmp", O_WRONLY | O_TRUNC | O_CREATE, 0777);
    if (fd < 3)
        return ;
    write(fd, "BM", 2);
    write(fd, &size, 4);
    write(fd, "\0\0\0\0", 4);
    write(fd, "6\0\0\0", 4);
    write(fd, "(\0\0\0", 4);
    write(fd, &scene->resolution.width, 4);
    write(fd, &scene->resolution.height, 4);
    write(fd, &pl, 2);
    write(fd, &deep_cl, 2);
}
