/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 20:11:06 by kboucaud          #+#    #+#             */
/*   Updated: 2017/11/03 20:11:08 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	put_pxl(t_data *data, int x, int y, unsigned int c)
{
	int		i;

	if (x * 4 >= WIN_LEN * 4 || x * 4 < 0)
		return ;
	i = (x * 4) + (y * data->s_l);
	data->image_string[i] = c;
	data->image_string[++i] = c >> 8;
	data->image_string[++i] = c >> 16;
}

void		ft_ray(t_rt *rt, int x, int y)
{
	int		color;

	color = 0x000000;
	while (rt->ray->z < 500 && color == 0x000000)
	{
		color = ft_check_object(rt);
		if (color == 0x000000)
			ft_add_vect(rt->ray, rt->dir);
	}
	if (color != 0x000000)
		put_pxl(rt->data, x, y, color);
}

void		ft_ini_ray(t_rt *rt, int x, int y)
{
	rt->ray_ori->x = x;
	rt->ray_ori->y = y;
	rt->ray_ori->z = 0;
	rt->ray = rt->ray_ori;
}

void		ft_raytracing(t_rt *rt)
{
	int			x;
	int			y;

	y = -1;
	while (++y <= WIN_HEIGHT)
	{
		x = -1;
		while (++x <= WIN_LEN)
		{
			ft_ini_ray(rt, x, y);
			ft_ray(rt, x, y);
		}
	}
	mlx_put_image_to_window(rt->data->mlx, rt->data->mlx_window, rt->data->mlx_image, 0, 0);
}
