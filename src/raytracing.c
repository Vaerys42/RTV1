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

void		ft_ray(t_rt *rt)
{
	int		color;

	color = 0x000000;
	while (rt->ray->z < 500 && color == 0x000000)
	{
		color = ft_check_object(rt);
		if (color == 0x000000)
			ft_add_vect(rt->ray, rt->dir);
	}
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
			ft_ray(rt);
		}
	}
}
