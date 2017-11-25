/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 01:04:26 by kboucaud          #+#    #+#             */
/*   Updated: 2017/10/21 03:59:13 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# define WIN_LEN 1000
# define WIN_HEIGHT 800

# include "libft/includes/libft.h"
# include "minilibx_macos/mlx.h"

typedef	struct			s_coo
{
	float				x;
	float				y;
	float				z;
}						t_coo;

typedef	struct			s_data
{
	void				*mlx;
	void				*mlx_window;
	void				*mlx_image;
	char 				*image_string;
	int					s_l;
	int					bpp;
	int					endian;
}						t_data;			

typedef	struct 			s_sphere
{
	int					type;
	t_coo				*ori;
	float				radius;
	int					color;
	void				*next;
}						t_sphere;

typedef	struct			s_rt
{
	t_data				*data;
	t_sphere			*object;
	t_coo				*ray;
	t_coo				*cam;
	t_coo				*dir;
	int					random;
}						t_rt;

void					ft_malloc_error(void);
void					ft_bad_arg(int i);
void					ft_exit(void);

void					ft_ini(t_rt *rt);

int						my_key_press(int key, t_rt *rt);
int						ft_exit_cross(t_rt *rt);
void					put_pxl(t_data *data, int x, int y, unsigned int c);

void					ft_parser(char *path, t_rt *rt);
void					ft_create_sphere(t_rt *rt, char **line);

void					ft_raytracing(t_rt *rt);

int						ft_check_object(t_rt *rt);

#endif
