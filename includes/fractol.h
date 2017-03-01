/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 19:44:22 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/01 21:31:54 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# define W_HEIGHT	1000.0
# define W_WIDTH	1000.0

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_fract
{
	char	name;
	t_point	min;
	t_point	max;
	t_point	zoom;
	t_point	ozoom;
	t_point	c;
	t_point	z;
	int		imax;
	char	*data;
	int		sizeline;
	int		bpp;
	void	(*f)(void *e, struct s_fract *fract, int x, int y);
}				t_fract;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	t_fract	fract[1];
}				t_env;
int				put_pixel_img(t_env *e, t_fract *f, int x, int y, unsigned int color);
int				map_pixels(t_env *e, t_fract *fract);
void			fractal_julia(void *e, t_fract *f, int x, int y);
int				handle_escape(int keycode, t_env *env);
int				handle_mouse(int button, int x, int y, t_env *env);
int				init_julia(t_env *e, t_fract *f);
int				fractol_core(t_env *env, t_fract *f);
#endif
