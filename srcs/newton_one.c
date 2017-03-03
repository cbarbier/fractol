/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:35:42 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/03 15:09:46 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int					init_newton_one(t_fract *f)
{
	f->min.x = -2.0;
	f->min.y = -1.5;
	f->max.x = 2.0;
	f->max.y = 1.5;
	f->zoom.x = W_WIDTH / (f->max.x - f->min.x);
	f->zoom.y = W_HEIGHT / (f->max.y - f->min.y);
	f->f = fractal_newton_one;
	f->imax = 42;
	return (1);
}

void				fractal_newton_one(int t, t_fract *f, int x, int y)
{
	int				i;
	double			tmp;
	t_point			z;
	t_point			c[2];
	t_coord			p;

	z.x = x / f->zoom.x + f->min.x;
	z.y = y / f->zoom.y + f->min.y;
	i = 0;
	while (i++ < f->imax && (z.x * z.x + z.y * z.y) < 4)
	{
		c[0].x = sin(z.x) * cosh(z.y) - 1;
		c[1].x = cos(z.x) * cosh(z.y) - 1;
		c[0].y = cos(z.x) * sinh(z.y);
		c[1].y = -sin(z.x) * sinh(z.y);
		tmp = z.x;
		z.x = (c[0].x * c[1].x + c[0].y * c[1].y) /
			(pow(c[1].x, 2.0) + pow(c[1].y, 2.0));
		z.y = (c[0].y * c[1].x - c[0].x * c[1].y) /
			(pow(c[1].x, 2.0) + pow(c[1].y, 2.0));
	}
	p.x = x;
	p.y = y % TH_STEP;
	put_pxl_img(t, f, &p, fractal_colorin(f, i));
}
