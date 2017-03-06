/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:35:42 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/06 12:39:38 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int					init_julia(t_fract *f)
{
	f->min.x = -2.0;
	f->min.y = -1.5;
	f->max.x = 2.0;
	f->max.y = 1.5;
	f->zoom.x = W_WIDTH / 4.0;
	f->zoom.y = W_HEIGHT / 3.0;
	f->f = fractal_julia;
	f->imax = 42;
	f->c.x = -0.7;
	f->c.y = 0.27015;
	return (1);
}

void				fractal_julia(int t, t_fract *f, int x, int y)
{
	int				i;
	double			tmp;
	t_point			z;
	t_coord			p;

	z.x = (x + f->dx) / f->zoom.x + f->min.x;
	z.y = (y + f->dy) / f->zoom.y + f->min.y;
	i = 0;
	while (i++ < f->imax && (z.x * z.x + z.y * z.y) < 4)
	{
		tmp = z.x;
		z.x = z.x * z.x - z.y * z.y + f->c.x;
		z.y = 2 * tmp * z.y + f->c.y;
	}
	p.x = x;
	p.y = y % TH_STEP;
	put_pxl_img(t, f, &p, fractal_colorin(f, i));
}
