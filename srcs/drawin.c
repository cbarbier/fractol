/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:25:39 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/01 15:32:30 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			put_pixel_img(t_env *e, t_fract *f, int x, int y, unsigned int color)
{
	char	*d;
	d = (f->data + (f->sizeline * y + x * f->bpp / 8));
	d[0] = (color & 0xFF0000) >> 16;
	d[1] = (color & 0x00FF00) >> 8;
	d[2] = (color & 0xFF);
	return (e ? 1 : 0);
}

int			map_pixels(t_env *e, t_fract *fract)
{
	int			x;
	int			y;

	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
			fract->f(e, fract, x++, y);
		y++;
	}
	return (1);
}
