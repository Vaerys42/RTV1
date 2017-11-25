
#include "../rtv1.h"

int			my_key_press(int key, t_rt *rt)
{
	if (key == 53)
	{
		mlx_destroy_window(rt->data->mlx, rt->data->mlx_window);
		exit(1);
	}
	return (0);
}