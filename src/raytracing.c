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
	if (i > WIN_HEIGHT * WIN_LEN * 4)
		return ;
	data->image_string[i] = c;
	data->image_string[++i] = c >> 8;
	data->image_string[++i] = c >> 16;
}

void		ft_ray(t_rt *rt, int x, int y)
{
	int 	color;

	color = ft_check_object(rt);
	if (color != 0x000000)
		put_pxl(rt->data, x, y, color);
}

void		ft_ini_ray(t_rt *rt, int x, int y)
{
	double		norm;

	rt->ray->o = ft_sub_vect(ft_add_vect(rt->view->up_left, ft_mult_vect(x,
	ft_mult_vect(rt->view->length / WIN_LEN, rt->cam->right))),
	ft_mult_vect(y, ft_mult_vect(rt->view->height / WIN_HEIGHT, rt->cam->up)));
	norm = ft_norm(rt->cam->pos, rt->ray->o);
	rt->ray->dir = ft_div_vect(norm, rt->ray->o);
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
