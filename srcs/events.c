/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:22:07 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/20 13:53:43 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

int			handle_escape(int keycode, t_env *env)
{
	if (env && keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == 8)
		env->fract->index_pallet += (env->fract->index_pallet == 2 ? -2 : 1);
	else if (keycode == 1)
		env->drag = env->drag ? 0 : 1;
	else if (keycode == 126)
		env->fract->dy += 5;
	else if (keycode == 124)
		env->fract->dx -= 5;
	else if (keycode == 125)
		env->fract->dy -= 5;
	else if (keycode == 123)
		env->fract->dx += 5;
	fractol_core(env, env->fract);
	return (0);
}

static int	zoom_in(int x, int y, t_fract *f)
{
	static int		count = 0;

	if (f->imax > 2147483647)
		return (0);
	f->ozoom.x = f->zoom.x;
	f->zoom.x *= 1.1;
	f->ozoom.y = f->zoom.y;
	f->zoom.y *= 1.1;
	f->min.x += x / f->ozoom.x - x / f->zoom.x;
	f->min.y += y / f->ozoom.y - y / f->zoom.y;
	if (!(count % 2))
		f->imax *= 1.038;
	return (0);
}

static int	zoom_out(int x, int y, t_fract *f)
{
	if (f->zoom.x < 30.0)
		return (0);
	f->ozoom.x = f->zoom.x;
	f->zoom.x /= 1.1;
	f->ozoom.y = f->zoom.y;
	f->zoom.y /= 1.1;
	f->min.x += x / f->ozoom.x - x / f->zoom.x;
	f->min.y += y / f->ozoom.y - y / f->zoom.y;
	if (f->imax > 42)
		f->imax /= 1.038;
	return (0);
}

int			mouse_motion(int x, int y, t_env *e)
{
	if (!e->drag || x % 5)
		return (0);
	e->fract->c.x = 0.001 * x;
	e->fract->c.y = 0.001 * y;
	fractol_core(e, e->fract);
	return (0);
}

int			handle_mouse(int button, int x, int y, t_env *env)
{
	int		i;

	i = 0;
	if ((button == 1 || button == 5))
		zoom_in(x, y, env->fract);
	else if ((button == 2 || button == 4))
		zoom_out(x, y, env->fract);
	fractol_core(env, env->fract);
	return (0);
}
