/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:04:11 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/03 15:58:29 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <pthread.h>
# include <math.h>
# define NB_THREAD	800
# define W_HEIGHT	800
# define W_WIDTH	800
# define TH_STEP	(W_HEIGHT / NB_THREAD)

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

typedef struct	s_fract
{
	char			name;
	t_point			min;
	t_point			max;
	t_point			zoom;
	t_point			ozoom;
	t_point			c;
	t_point			z;
	int				dx;
	int				dy;
	intmax_t		imax;
	char			*data[NB_THREAD];
	int				index[NB_THREAD];
	int				sizeline;
	int				bpp;
	unsigned int	pallet[3][5];
	int				index_pallet;
	void			(*f)(int t, struct s_fract *fract, int x, int y);
}				t_fract;
typedef struct	s_param
{
	t_fract	*f;
	int		index;
}				t_param;
typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img[NB_THREAD];
	t_param		params[NB_THREAD];
	t_fract		fract[1];
	char		drag;
}				t_env;
void			put_pxl_img(int t, t_fract *f, t_coord *p, unsigned int c);
unsigned int	fractal_colorin(t_fract *f, int i);
int				map_pixels(t_env *e);
int				handle_escape(int keycode, t_env *env);
int				handle_mouse(int button, int x, int y, t_env *env);
int				mouse_motion(int x, int y, t_env *e);
int				init_julia(t_fract *f);
void			fractal_julia(int t, t_fract *f, int x, int y);
int				init_mandel(t_fract *f);
void			fractal_mandel(int t, t_fract *f, int x, int y);
int				init_newton_one(t_fract *f);
void			fractal_newton_one(int t, t_fract *f, int x, int y);
int				init_newton_two(t_fract *f);
void			fractal_newton_two(int t, t_fract *f, int x, int y);
int				fractol_core(t_env *env, t_fract *f);
void			*map_a_quarter(void *param);
#endif
