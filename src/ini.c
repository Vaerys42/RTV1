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
	rt->sphere->radius = 200;
	rt->sphere->color = 0x01FE2B;
	rt->sphere->next = NULL;
	rt->sphere->o->x = 350;
	rt->sphere->o->y = 400;
	rt->sphere->o->z = 100;
}

void	ft_ini_plane(t_rt *rt)
{
	if (!(rt->plane = (t_plane*)malloc(sizeof(t_plane))))
		ft_malloc_error();
	if (!(rt->plane->norm = (t_coo*)malloc(sizeof(t_coo))))
		ft_malloc_error();
	rt->plane->color = 0x1201FE;
	rt->plane->next = NULL;
	rt->plane->norm->x = 0;
	rt->plane->norm->y = 10;
	rt->plane->norm->z = 0;
	rt->plane->dst = 200;
}

void	ft_ini(t_rt *rt)
{
	ft_create(rt);
	if (!(rt->ray = (t_ray*)malloc(sizeof(t_ray))))
		ft_malloc_error();
	if (!(rt->cam = (t_ray*)malloc(sizeof(t_ray))))
		ft_malloc_error();
	if (!(rt->ray->dir = (t_coo*)malloc(sizeof(t_coo))))
		ft_malloc_error();
	if (!(rt->ray_ori = (t_coo*)malloc(sizeof(t_coo))))
		ft_malloc_error();
	if (!(rt->cam->dir = (t_coo*)malloc(sizeof(t_coo))))
		ft_malloc_error();
	if (!(rt->cam->o = (t_coo*)malloc(sizeof(t_coo))))
		ft_malloc_error();
	rt->cam->o->x = 100;
	rt->cam->o->y = 100;
	rt->cam->o->z = 0;
	rt->cam->dir->x = 0;
	rt->cam->dir->y = 0;
	rt->cam->dir->z = 1;
	rt->ray->dir = rt->cam->dir;
	//rt->up_left = ft_add_vect(rt->cam->o, ft_add_vect(ft_vect_mult(100, rt->cam->dir), ft_vect_mult()))
	ft_ini_sphere(rt);
	ft_ini_plane(rt);
}
