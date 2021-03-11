#include "mlx/mlx.h"
typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char 		*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*((unsigned int*)dst) = color;
}

int 			main()
{
	void	*mlx_ptr;
	void	*mlx_window_ptr;
	t_data	img;
	int i = 0;
	int j = 0;

	mlx_ptr = mlx_init();
	mlx_window_ptr = mlx_new_window(mlx_ptr, 100, 100, "karina mlx");
	img.img = mlx_new_image(mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
									&img.line_length, &img.endian);
	//my_mlx_pixel_put(&img, 50, 50, 0x00FFFFFF);
	//my_mlx_pixel_put(&img, 501, 501, 0x00FFFFFF);
	//my_mlx_pixel_put(&img, 502, 502, 0x00FFFFFF);
    //mlx_put_image_to_window(mlx_ptr, mlx_window_ptr, img.img, 0, 0);
	while (i < 100)
	{
		j = 0;
		while (j < 100)
		{
			my_mlx_pixel_put(&img, i, j, 0x00FFFFFF);
			//mlx_pixel_put(mlx_ptr, mlx_window_ptr, i, j, 0x00FFFFFF);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx_ptr, mlx_window_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
}
