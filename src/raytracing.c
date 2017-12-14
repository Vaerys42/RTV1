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
			ft_ray(rt, x, y);
		}
	}
	mlx_put_image_to_window(rt->data->mlx, rt->data->mlx_window, rt->data->mlx_image, 0, 0);
}
