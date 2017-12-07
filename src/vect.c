/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 03:32:16 by kboucaud          #+#    #+#             */
/*   Updated: 2017/12/04 03:32:18 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void		ft_add_vect(t_coo *vect1, t_coo *vect2)
{
	vect1->x += vect2->x;
	vect1->y += vect2->y;
	vect1->z += vect2->z;
}


double		scal(t_coo *vect1, t_coo *vect2)
{
	double		rslt;

	rslt = vect1->x * vect2->x + vect1->y * vect2->y + vect1->z * vect2->z;
	return (rslt);
}