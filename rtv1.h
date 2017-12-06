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
# include "math.h"

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
	int					*image_int;
}						t_data;			

typedef struct 			s_cylinder
{
	t_coo				*o;
	float				radius;
	int					color;
	float				height;
}						t_cylinder;

typedef	struct 			s_cone
{
	t_coo				*o;
	float				radius;
	int					color;
	float				height;
	struct s_cone		*next;
}						t_cone;

typedef	struct 			s_sphere
{
	t_coo				*o;
	float				radius;
	int					color;
	struct s_sphere		*next;
}						t_sphere;

typedef	struct 			s_plane
{
	int					color;
	t_coo				*o;
	struct s_plane		*next;
}						t_plane;

typedef	struct 			s_ray
{
	t_coo				*o;
	t_coo				*dir;
}						t_ray;

typedef	struct			s_rt
{
	t_data				*data;
	t_coo				*ray;
	t_coo				*cam;
	t_coo				*dir;
	int					random;
	t_sphere			*sphere;
	t_plane				*plane;
	t_coo				*ray_ori;
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

void					ft_add_vect(t_coo *vect1, t_coo *vect2);

#endif
