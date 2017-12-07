/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 00:31:27 by kboucaud          #+#    #+#             */
/*   Updated: 2017/11/03 00:31:29 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"
/*
int			ft_check_plane(t_rt *rt)
{
	double	result;

	result = 
	if (result == 0)
		return (rt->plane->color);
	return (0x000000);
}
*/
int			ft_check_sphere(t_rt *rt)
{
	double	b;
	double	c;
	double	det;

	b = 2 * (rt->ray->dir->x * (rt->ray_ori->x - rt->sphere->o->x) + rt->ray->dir->y * (rt->ray_ori->y 
	- rt->sphere->o->y) + rt->ray->dir->z * (rt->ray_ori->z - rt->sphere->o->z));
	c = (pow(rt->ray_ori->x - rt->sphere->o->x, 2) + pow(rt->ray_ori->y - rt->sphere->o->y, 2)
	+ pow(rt->ray_ori->z - rt->sphere->o->z, 2)) - pow(rt->sphere->radius, 2);
	det = b * b - 4 * c;
	if (det >= 0)
		return (rt->sphere->color);
	return (0x000000);
}

int			ft_check_object(t_rt *rt)
{
	int		color;

/*	color = ft_check_plane(rt);
	if (color != 0x000000)
		return (color);*/
	color = ft_check_sphere(rt);
	if (color != 0x000000)
		return (color);
	return (0x000000);
}
