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

t_coo		*ft_mult_vect(float i, t_coo *vect)
{
	t_coo	*new;

	if (!(new = (t_coo*)malloc(sizeof(t_coo))))
		ft_malloc_error();
	new->x = i * vect->x;
	new->y = i * vect->y;
	new->z = i * vect->z;
	printf("mult\n");
	return (new);
}

t_coo		*ft_add_vect(t_coo *vect1, t_coo *vect2)
{
	t_coo	*new;

	if (!(new = (t_coo*)malloc(sizeof(t_coo))))
		ft_malloc_error();
	new->x = vect1->x + vect2->x;
	new->y = vect1->y + vect2->y;
	new->z = vect1->z + vect2->z;
	printf("add\n");	
	return (new);
}

t_coo		*ft_sub_vect(t_coo *vect1, t_coo *vect2)
{
	t_coo	*new;

	if (!(new = (t_coo*)malloc(sizeof(t_coo))))
		ft_malloc_error();
	new->x = vect1->x - vect2->x;
	new->y = vect1->y - vect2->y;
	new->z = vect1->z - vect2->z;
	printf("sub\n");
	return (new);	
}

double		scal(t_coo *vect1, t_coo *vect2)
{
	double		rslt;

	rslt = vect1->x * vect2->x + vect1->y * vect2->y + vect1->z * vect2->z;
	return (rslt);
}