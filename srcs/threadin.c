/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:33:26 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/02 18:48:56 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		*map_a_quarter(void *param)
{
	int				x;
	int				y;
	int				end;
	t_fract			*f;
	t_param			*p;

	p = (t_param *)param;
	f = p->f;
	y = p->index * TH_STEP;
	end = y + TH_STEP;
	while (y < end)
	{
		x = 0;
		while (x < W_WIDTH)
			f->f(p->index, f, x++, y);
		y++;
	}
	ft_printf("y: %d\n", y);
	return (0);
}
