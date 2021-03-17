#include "includes/header_struct.h"
#include "includes/header_func.h"
#include "includes/vector.h"

int 			main()
{
	t_camera	camera;
	t_vec		view;
	t_point		point_of_view;
	t_wind		window;

	window = fill_wind(1920, 1080);
	point_of_view =  fill_point(0, 0, 0);
	view = fill_vector(0, 0, 1);
	camera = fill_camera(point_of_view, view, (double)80, window);
return (0);
}
