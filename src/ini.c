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
	if ((rt->data = (t_data*)malloc(sizeof(t_data))) == NULL)
		ft_malloc_error();
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
		ft_exit();
	/*if ((rt->data->window = SDL_CreateWindow("RTV1", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, 1000, 800, SDL_WINDOW_SHOWN)) == NULL)
		ft_exit();*/
}

void	ft_ini_sphere(t_rt *rt)
{
	if ((rt->object = (t_sphere*)malloc(sizeof(t_sphere))) == NULL)
		ft_malloc_error();
	if ((rt->object->ori = (t_coo*)malloc(sizeof(t_coo))) == NULL)
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
	if ((rt->ray = (t_coo*)malloc(sizeof(t_coo))) == NULL)
		ft_malloc_error();
	if ((rt->cam = (t_coo*)malloc(sizeof(t_coo))) == NULL)
		ft_malloc_error();
	if ((rt->dir = (t_coo*)malloc(sizeof(t_coo))) == NULL)
		ft_malloc_error();
	ft_ini_sphere(rt);
	rt->cam->x = WIN_LEN / 2;
	rt->cam->y = WIN_HEIGHT / 2;
	rt->cam->z = 0;
	rt->dir->x = 0;
	rt->dir->y = 0;
	rt->dir->z = 0.66;
}
