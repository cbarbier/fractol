/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:35:42 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/02 15:54:07 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		init_julia(t_fract *f)
{
	f->min.x = -2.0;
	f->min.y = -1.5;
	f->max.x = 2.0;
	f->max.y = 1.5;
	f->zoom.x = W_WIDTH / 4.0;
	f->zoom.y = W_HEIGHT / 3.0;
	f->f = fractal_julia;
	f->imax = 42;
	return (1);
}

static unsigned int	color_julia(t_fract *f, int i)
{
	if (i < f->imax)
		return (0xFFFFFF / i);
	return (0);
}

void				fractal_julia(int t, t_fract *f, int x, int y)
{
	int				i;
	double			tmp;
	t_point			c;
	t_point			z;
	t_coord			p;

	z.x =  x / f->zoom.x + f->min.x;
	z.y =  y / f->zoom.y + f->min.y;
	c.x = -0.7;
	c.y = 0.27015;
	i = 0;
	while (i++ < f->imax && (z.x * z.x + z.y * z.y) < 4)
	{
		tmp = z.x;
		z.x = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * tmp * z.y + c.y;
	}
	p.x = x;
	p.y = y % TH_STEP;
	put_pxl_img(t, f, &p, color_julia(f, i));
}
