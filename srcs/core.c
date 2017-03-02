/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:00:10 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/02 18:46:41 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			fractol_core(t_env *e, t_fract *f)
{
	int		ed;
	int		i;

	i = 0;
	while (i < NB_THREAD)
	{
		if (!(e->img[i] = mlx_new_image(e->mlx, W_WIDTH, TH_STEP)))
			return (0);
		f->data[i] = mlx_get_data_addr(e->img[i], &(f->bpp), &(f->sizeline), &ed);
		i++;
	}
	mlx_clear_window(e->mlx, e->win);
	map_pixels(e);
	i = 0;
	while (i < NB_THREAD)
	{
		mlx_put_image_to_window(e->mlx, e->win, e->img[i], 0, i * TH_STEP);
		mlx_destroy_image(e->mlx, e->img[i]);
		i++;
	}
	return (1);
}
