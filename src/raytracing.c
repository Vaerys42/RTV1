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

void		ft_raytracing(t_rt *rt)
{
	int			x;
	int			y;
	int			color;

	y = -1;
	while (++y <= WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_LEN)
		{
			color = 0x000000;
			rt->ray->x = x - rt->cam->x;
			rt->ray->y = y - rt->cam->y;
			rt->ray->z = 100 - rt->cam->z;
			while (color == 0x000000 && rt->ray->z < 400)
			{
				color = ft_check_object(rt);
				rt->ray->z += rt->dir->z;
			}
		}
	}
}
