/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:48:08 by cbarbier          #+#    #+#             */
/*   Updated: 2017/02/28 15:08:43 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int			handle_escape(int keycode, t_env *env)
{
	if (env && keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

static int			handle_scroll(int button, int x, int y, t_env *env)
{
	if (x && y && env)
		ft_printf("button clicked id: %d\n", button);
	if (button == 1 || button == 4)
	{
		env->ozx = env->zx;
		env->zx *= 1.1;
		env->ozy = env->zy;
		env->zy *= 1.1;
		build_img(env, 0.0 + x, 0.0 + y);
	}
	else if (button == 2)
	{
		env->ozx = env->zx;
		env->zx /= 1.1;
		env->ozy = env->zy;
		env->zy /= 1.1;
		build_img(env, 0.0 + x, 0.0 + y);
	}

	return (0);
}

void				put_pix_img(char *data, int sl, int bpp, int x, int y, unsigned int color)
{
	data[sl * y + x * bpp / 8] = (color & 0xFF0000) >> 16; 
	data[sl * y + x * bpp / 8 + 1] = (color & 0x00FF00) >> 8;
	data[sl * y + x * bpp / 8 + 2] = (color & 0x0000FF);
}

int				build_img(t_env *env, double  mx, double my)
{
	static int	nbcall = 0;
	char		*data;
	int			i;
	int			bpp;
	int			size_line;
	int			endian;
	int			val;
	int			x;
	int			y;
	double		zr;
	double		zi;
	double		ozr;
	double		ozi;
	double		cr;
	double		ci;
	static double		minx;
	static double		miny;
	static double		maxx;
	static double		maxy;
	static double		omx = 500.0;
	static double		omy = 500.0;


	if (!nbcall)
	{
		minx = -2.0;
		maxx = 2.0;
		miny = -1.5;
		maxy = 1.5;
		env->zx = 1000.0 / (maxx - minx);
		env->zy = 1000.0 / (maxy - miny);
	}
	else
	{
		minx += mx / env->ozx - mx / env->zx;
		miny += my / env->ozy - my / env->zy;
	}
	ft_printf("minx: %f\nmaxx: %f\nminy: %f\nmaxy: %f\n", minx, maxx, miny, maxy);
	if (!(env->img = mlx_new_image(env->mlx, 1000, 1000)))
		return (0);	
	data = mlx_get_data_addr(env->img, &bpp, &size_line, &endian);
	y = 0;
	val = 1;
	while (y < 1000.0)
	{
		x = 0;
		while (x < 1000.0)
		{
			cr =  x / env->zx + minx;
			ci =  y / env->zy + miny;
			zr = 0.0;
			zi = 0.0;
			i = 0;
			while (i++ < 256 && (val = zr * zr + zi * zi) < 4)
			{
				ozi = zi;
				ozr = zr;
				zr = ozr * ozr - ozi * ozi + cr;
				zi = 2 * ozr * ozi + ci;
			}
			if (i != 256)
			{
				val = 0xffffff / i;
				put_pix_img(data, size_line, bpp, x, y, mlx_get_color_value(env->mlx, val));
			}
			else
				put_pix_img(data, size_line, bpp, x, y, mlx_get_color_value(env->mlx, 0));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
	nbcall++;
	omx = mx;
	omy = my;
	return (0);
}

int				fractol(t_env *env)
{
	mlx_key_hook(env->win, handle_escape, env);
	mlx_mouse_hook(env->win, handle_scroll, env);
	mlx_loop(env->mlx);
	return (1);
}
