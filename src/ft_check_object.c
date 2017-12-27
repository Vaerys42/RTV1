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
float			ft_check_sphere(t_rt *rt)
{
	double	a;
	double	b;
	double	c;
	double	det;

	a = pow(rt->ray->dir->x, 2) + pow(rt->ray->dir->y, 2) + pow(rt->ray->dir->z, 2);
	b = 2 * (rt->ray->dir->x * (rt->ray->o->x - rt->sphere->o->x) + rt->ray->dir->y * (rt->ray->o->y 
	- rt->sphere->o->y) + rt->ray->dir->z * (rt->ray->o->z - rt->sphere->o->z));
	c = (pow(rt->ray->o->x - rt->sphere->o->x, 2) + pow(rt->ray->o->y - rt->sphere->o->y, 2)
	+ pow(rt->ray->o->z - rt->sphere->o->z, 2)) - pow(rt->sphere->radius, 2);
	det = b * b - 4 * a * c;
	if (det >= 0)
	{
		if (((-b - sqrt(det)) / (2 * a)) > ((-b + sqrt(det)) / (2 * a)))
			return ((-b + sqrt(det)) / (2 * a));
		return (((-b - sqrt(det)) / (2 * a)));
	}
	return (0);
}

void			ft_check_object(t_rt *rt)
{
	float		dst;

/*	color = ft_check_plane(rt);
	if (color != 0x000000)
		return (color);*/
	dst = 0;
	dst = ft_check_sphere(rt);
	rt->color = rt->plane->color;
	if (dst != 0)
		rt->color = rt->sphere->color;
	return ;
}
