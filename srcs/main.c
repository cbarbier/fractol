/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 19:47:59 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/01 17:13:16 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		init_env(t_env *env)
{
	ft_bzero(env, sizeof(t_env));
	if (!(env->mlx = mlx_init()))
		return (0);
	if (!(env->win = mlx_new_window(env->mlx, W_WIDTH, W_HEIGHT, "fractol")))
		return (0);
	if (!(env->img = mlx_new_image(env->mlx, W_WIDTH, W_HEIGHT)))
		return (0);
	init_julia(env->fract);
	return (1);
}

int				main(int argc, char **argv)
{
	t_env		env;

	if (argc != 1 || !argv[0])
	{
		ft_putendl_fd("usage: ./fractol [julia|mandelbrot]", 2);
		return (0);
	}
	if (!init_env(&env))
		return (1);
	fractol_core(&env, env.fract);
	mlx_key_hook(env.win, handle_escape, &env);
	mlx_mouse_hook(env.win, handle_mouse, &env);
	mlx_loop(env.mlx);
	return (0);
}
