/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:35:42 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/06 12:39:58 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int					init_mandel(t_fract *f)
{
	f->min.x = -2.0;
	f->min.y = -1.5;
	f->max.x = 2.0;
	f->max.y = 1.5;
	f->zoom.x = W_WIDTH / 4.0;
	f->zoom.y = W_HEIGHT / 3.0;
	f->f = fractal_mandel;
	f->imax = 42;
	return (1);
}

void				fractal_mandel(int t, t_fract *f, int x, int y)
{
	int				i;
	double			tmp;
	t_point			c;
	t_point			z;
	t_coord			p;

	c.x = x / f->zoom.x + f->min.x;
	c.y = y / f->zoom.y + f->min.y;
	z.x = 0.0;
	z.y = 0.0;
	i = 0;
	while (i++ < f->imax && (z.x * z.x + z.y * z.y) < 4)
	{
		tmp = z.x;
		z.x = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * tmp * z.y + c.y;
	}
	p.x = x;
	p.y = y % TH_STEP;
	put_pxl_img(t, f, &p, fractal_colorin(f, i));
}
