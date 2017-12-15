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
# define PLN_DST 1

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
	t_coo				*norm;
	int 				dst;
	struct s_plane		*next;
}						t_plane;

typedef	struct 			s_ray
{
	t_coo				*o;
	t_coo				*dir;
	t_coo				*act;
}						t_ray;

typedef	struct 			s_cam
{
	t_coo				*pos;
	t_coo				*forw;
	t_coo				*up;
	t_coo				*right;
}						t_cam;

typedef	struct 			s_view
{
	float 				screen_ratio;
	float				height;
	float				length;
	t_coo				*up_left;
}						t_view;

typedef	struct			s_rt
{
	t_data				*data;
	t_ray				*ray;
	t_cam				*cam;
	t_sphere			*sphere;
	t_plane				*plane;
	t_view				*view;
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

t_coo					*ft_add_vect(t_coo *vect1, t_coo *vect2);
double					scal(t_coo *vect1, t_coo *vect2);
t_coo					*ft_mult_vect(float i, t_coo *vect);
t_coo					*ft_sub_vect(t_coo *vect1, t_coo *vect2);
double					ft_norm(t_coo *vect1, t_coo *vect2);
t_coo					*ft_div_vect(float i, t_coo *vect);

#endif
