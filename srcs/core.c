/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:00:10 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/06 12:49:37 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			fractol_core(t_env *e, t_fract *f)
{
	int		ed;
	int		i;
	char	*data;

	if (!(e->img = mlx_new_image(e->mlx, W_WIDTH, W_HEIGHT)))
		return (0);
	data = mlx_get_data_addr(e->img, &(f->bpp), &(f->sizeline), &ed);
	i = 0;
	while (i < NB_THREAD)
	{
		f->data[i] = data + i * TH_STEP * f->sizeline;
		i++;
	}
	mlx_clear_window(e->mlx, e->win);
	map_pixels(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
	return (1);
}
