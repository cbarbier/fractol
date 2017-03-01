/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:22:07 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/01 17:27:28 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			handle_escape(int keycode, t_env *env)
{
	if (env && keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

static int	zoom_in(t_env *env, int x, int y, t_fract *f)
{
	f->ozoom.x = f->zoom.x;
	f->zoom.x *= 1.1;
	f->ozoom.y = f->zoom.y;
	f->zoom.y *= 1.1;
	f->min.x += x / f->ozoom.x - x / f->zoom.x;
	f->min.y += y / f->ozoom.y - y / f->zoom.y;
	f->imax *= 1.1;
	fractol_core(env, f);
	return (0);
}

static int	zoom_out(t_env *env, int x, int y, t_fract *f)
{
	f->ozoom.x = f->zoom.x;
	f->zoom.x /= 1.1;
	f->ozoom.y = f->zoom.y;
	f->zoom.y /= 1.1;
	f->min.x += x / f->ozoom.x - x / f->zoom.x;
	f->min.y += y / f->ozoom.y - y / f->zoom.y;
	f->imax /= 1.1;
	fractol_core(env, f);
	return (0);
}

int			handle_mouse(int button, int x, int y, t_env *env)
{
	ft_printf("button clicked id: %d\n", button);
	if (button == 1 || button == 3)
		zoom_in(env, x, y, env->fract);
	else if (button == 2 || button == 4)
		zoom_out(env, x, y, env->fract);
	return (0);
}
