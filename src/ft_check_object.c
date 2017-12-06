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
int			ft_check_sphere(t_rt *rt)
{
	float			check;

	check = ((rt->ray_ori->x - rt->sphere->o->x) * (rt->ray_ori->x - rt->sphere->o->x))
	+ ((rt->ray_ori->y - rt->sphere->o->y) * (rt->ray_ori->y - rt->sphere->o->y))
	+ ((rt->ray_ori->z - rt->sphere->o->z) * (rt->ray_ori->z - rt->sphere->o->z));
	if (check <= (rt->sphere->radius * rt->sphere->radius))
		return (rt->sphere->color);
	return (0x000000);
}*/

int			ft_check_sphere(t_rt *rt)
{
	double	a;
	double	b;
	double	c;
	double	det;

	a = (rt->dir->x * rt->dir->x) + (rt->dir->y * rt->dir->y) + (rt->dir->z * rt->dir->z);
	b = 2 * (rt->dir->x * (rt->ray_ori->x - rt->sphere->o->x) + rt->dir->y * (rt->ray_ori->y 
	- rt->sphere->o->y) + rt->dir->z * (rt->ray_ori->z - rt->sphere->o->z));
	c = (pow(rt->ray_ori->x - rt->sphere->o->x, 2) + pow(rt->ray_ori->y - rt->sphere->o->y, 2)
	+ pow(rt->ray_ori->z - rt->sphere->o->z, 2)) - pow(rt->sphere->radius, 2);
	det = b * b - 4 * a * c;
	if (det >= 0)
		return (rt->sphere->color);
	return (0x000000);
}

int			ft_check_object(t_rt *rt)
{
	int		color;

	color = ft_check_sphere(rt);
	if (color != 0x000000)
		return (color);
	return (0x000000);
}
