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

void	zero_color(t_rt *rt)
{
	rt->color->r = 0;
	rt->color->g = 0;
	rt->color->b = 0;
}

void	put_pxl(t_data *data, int x, int y, t_color *color)
{
	int		i;

	if (x * 4 >= WIN_LEN * 4 || x * 4 < 0)
		return ;
	i = (x * 4) + (y * data->s_l);
	if (i > WIN_HEIGHT * WIN_LEN * 4)
		return ;
	if (color->g != 0)
		printf("%f %f %f\n", color->r, color->g, color->b);
	data->image_string[i] = color->r;
	data->image_string[++i] = color->g;
	data->image_string[++i] = color->b;
}

void		ft_convert(t_rt *rt)
{
	rt->color->r = (int)(rt->color->r * 255);
	rt->color->g = (int)(rt->color->g * 255);
	rt->color->b = (int)(rt->color->b * 255);
}

void		ft_ray(t_rt *rt, int x, int y)
{
	ft_check_object(rt);
	//if (rt->color->r == 0 && rt->color->g == 0 && rt->color->b == 0)
	//	return ;
	ft_convert(rt);
	put_pxl(rt->data, x, y, rt->color);
}

void		ft_ini_ray(t_rt *rt, int x, int y)
{
	double		norm;

	zero_color(rt);
	rt->ray->o = ft_sub_vect(ft_add_vect(rt->view->up_left, ft_mult_vect(x, ft_mult_vect(rt->view->length / WIN_LEN, rt->cam->right))), ft_mult_vect(y, ft_mult_vect(rt->view->height / WIN_HEIGHT, rt->cam->up)));
	rt->ray->dir = ft_sub_vect(rt->cam->pos, rt->ray->o);
	norm = ft_norm_2(rt->ray->dir);
	rt->ray->dir = ft_div_vect(norm, rt->ray->dir);
}

void		ft_raytracing(t_rt *rt)
{
	int			x;
	int			y;

	y = -1;
	while (++y <= 25)
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
