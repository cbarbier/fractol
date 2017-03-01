/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:00:10 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/01 17:24:40 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			fractol_core(t_env *env, t_fract *f)
{
	int		e;

	if (!(env->img = mlx_new_image(env->mlx, W_WIDTH, W_HEIGHT)))
		return (0);
	f->data = mlx_get_data_addr(env->img, &(f->bpp), &(f->sizeline), &e);
	map_pixels(env, f);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
	return (1);
}
