/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 01:04:42 by kboucaud          #+#    #+#             */
/*   Updated: 2017/10/21 01:09:54 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	ft_create(t_rt *rt)
{
	if (!(rt->data = (t_data*)malloc(sizeof(t_data))))
		ft_malloc_error();
	rt->data->mlx = mlx_init();
	rt->data->mlx_window = mlx_new_window(rt->data->mlx, WIN_LEN, WIN_HEIGHT, "RTV1");
	rt->data->mlx_image = mlx_new_image(rt->data->mlx, WIN_LEN, WIN_HEIGHT);
	rt->data->image_string = mlx_get_data_addr(rt->data->mlx_image, &rt->data->bpp, &rt->data->s_l, &rt->data->endian);
}

void	ft_ini_sphere(t_rt *rt)
{
	if (!(rt->object = (t_sphere*)malloc(sizeof(t_sphere))))
		ft_malloc_error();
	if (!(rt->object->ori = (t_coo*)malloc(sizeof(t_coo))))
		ft_malloc_error();
	rt->object->type = 1;
	rt->object->radius = 300;
	rt->object->color = 0xFFFFFF;
	rt->object->next = NULL;
	rt->object->ori->x = 200;
	rt->object->ori->z = 200;
	rt->object->ori->z = 200;
}

void	ft_ini(t_rt *rt)
{
	ft_create(rt);
	if (!(rt->ray = (t_coo*)malloc(sizeof(t_coo))))
		ft_malloc_error();
	if (!(rt->cam = (t_coo*)malloc(sizeof(t_coo))))
		ft_malloc_error();
	if (!(rt->dir = (t_coo*)malloc(sizeof(t_coo))))
		ft_malloc_error();
	ft_ini_sphere(rt);
	rt->cam->x = WIN_LEN / 2;
	rt->cam->y = WIN_HEIGHT / 2;
	rt->cam->z = 0;
	rt->dir->x = 0;
	rt->dir->y = 0;
	rt->dir->z = 0.66;
}
