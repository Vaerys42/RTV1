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
	if (!(rt->data->image_int = (int*)malloc(sizeof(int) * WIN_LEN * WIN_HEIGHT)))
		ft_malloc_error();
	if (!(rt->data->mlx = mlx_init()))
		ft_exit();
	if (!(rt->data->mlx_window = mlx_new_window(rt->data->mlx, WIN_LEN, WIN_HEIGHT, "RTV1")))
		ft_exit();
	if (!(rt->data->mlx_image = mlx_new_image(rt->data->mlx, WIN_LEN, WIN_HEIGHT)))
		ft_exit();
	if (!(rt->data->image_string = mlx_get_data_addr(rt->data->mlx_image, &rt->data->bpp, &rt->data->s_l, &rt->data->endian)))
		ft_exit();
	rt->data->image_int = (int*)rt->data->image_string;
}

void	ft_ini_sphere(t_rt *rt)
{
	if (!(rt->sphere = (t_sphere*)malloc(sizeof(t_sphere))))
		ft_malloc_error();
	if (!(rt->sphere->o = (t_coo*)malloc(sizeof(t_coo))))
		ft_malloc_error();
	rt->sphere->radius = 300;
	rt->sphere->color = 0xFFFFFF;
	rt->sphere->next = NULL;
	rt->sphere->o->x = 350;
	rt->sphere->o->y = 300;
	rt->sphere->o->z = 200;
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
	if (!(rt->ray_ori = (t_coo*)malloc(sizeof(t_coo))))
		ft_malloc_error();
	rt->cam->x = 100;
	rt->cam->y = 100;
	rt->cam->z = 0;
	rt->dir->x = 0;
	rt->dir->y = 0;
	rt->dir->z = 1;
	ft_ini_sphere(rt);
}
