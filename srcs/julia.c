/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:35:42 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/01 18:29:14 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		init_julia(t_env *env, t_fract *f)
{
	f->min.x = -2.0;
	f->min.y = -1.5;
	f->max.x = 2.0;
	f->max.y = 1.5;
	f->zoom.x = W_WIDTH / 4.0;
	f->zoom.y = W_HEIGHT / 3.0;
	f->f = fractal_julia;
	f->imax = 42;
	if (!(env->img = mlx_new_image(env->mlx, W_WIDTH, W_HEIGHT)))
		return (0);
	return (1);
}

static unsigned int	color_julia(t_fract *f, int i)
{
	if (i < f->imax)
		return (0xFFFFFF / i);
	return (0);
}

void				fractal_julia(void *e, t_fract *f, int x, int y)
{
	int			i;
	double		tmp;

	f->c.x =  x / f->zoom.x + f->min.x;
	f->c.y =  y / f->zoom.y + f->min.y;
	f->z.x = 0.0;
	f->z.y = 0.0;
	i = 0;
	while (i++ < f->imax && (f->z.x * f->z.x + f->z.y * f->z.y) < 4)
	{
		tmp = f->z.x;
		f->z.x = f->z.x * f->z.x - f->z.y * f->z.y + f->c.x;
		f->z.y = 2 * tmp * f->z.y + f->c.y;
	}
	put_pixel_img((t_env *)e, f, x, y, color_julia(f, i));
}
