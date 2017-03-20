/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:35:42 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/20 13:55:28 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int					init_newton_two(t_fract *f)
{
	f->min.x = -2.0;
	f->min.y = -1.5;
	f->max.x = 2.0;
	f->max.y = 1.5;
	f->zoom.x = W_WIDTH / (f->max.x - f->min.x);
	f->zoom.y = W_HEIGHT / (f->max.y - f->min.y);
	f->f = fractal_newton_two;
	f->imax = 42;
	return (1);
}

void				fractal_newton_two(int t, t_fract *f, int x, int y)
{
	int				i;
	double			tmp;
	t_point			z;
	t_point			c;
	t_coord			p;

	z.x = x / f->zoom.x + f->min.x;
	z.y = y / f->zoom.y + f->min.y;
	c.x = 0.5667;
	c.y = 0.5667;
	i = 0;
	while (i++ < f->imax && (z.x * z.x + z.y * z.y) < 4)
	{
		tmp = z.x;
		z.x = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * fabs(tmp * z.y) + c.y;
	}
	p.x = x;
	p.y = y % TH_STEP;
	put_pxl_img(t, f, &p, fractal_colorin(f, i));
}
