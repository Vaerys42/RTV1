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

int			ft_check_sphere(t_coo *coo, t_sphere *sph)
{
	float		x;
	float		y;
	float		z;
	float		check;

	x = coo->x - sph->ori->x;
	y = coo->y - sph->ori->y;
	z = coo->z - sph->ori->z;
	check = (x * x) + (y * y) + (z * z);
	if (check == (sph->radius * sph->radius))
		return (sph->color);
	return (0x000000);
}

int			ft_check_object(t_rt *rt)
{
	if (rt->object->type == 1)
		return (ft_check_sphere(rt->ray, rt->object));
	return (0x000000);
}
