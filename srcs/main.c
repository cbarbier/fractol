/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 19:47:59 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/21 17:22:46 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		set_pallet(t_fract *f)
{
	f->pallet[0][0] = 0x61b3ff;
	f->pallet[0][1] = 0x210a7f;
	f->pallet[0][2] = 0x0588da;
	f->pallet[0][3] = 0x0bcc31;
	f->pallet[0][4] = 0x21fd2b;
	f->pallet[1][0] = 0xee671d;
	f->pallet[1][1] = 0xb84818;
	f->pallet[1][2] = 0x6f300d;
	f->pallet[1][3] = 0x291c16;
	f->pallet[1][4] = 0x131110;
	f->pallet[2][0] = 0xff0000;
	f->pallet[2][1] = 0xff435a;
	f->pallet[2][2] = 0xf95ebf;
	f->pallet[2][3] = 0xbe7cfc;
	f->pallet[2][4] = 0x9eabff;
	return (1);
}

static int		init_env(t_env *env, char l)
{
	ft_bzero(env, sizeof(t_env));
	if (!(env->mlx = mlx_init()))
		return (0);
	if (!(env->win = mlx_new_window(env->mlx, W_WIDTH, W_HEIGHT, "fractol")))
		return (0);
	if (l == 'j' && (env->fract->name = l))
		init_julia(env->fract);
	else if (l == 'm' && (env->fract->name = l))
		init_mandel(env->fract);
	else if (l == '1' && (env->fract->name = l))
		init_newton_one(env->fract);
	else if (l == '2' && (env->fract->name = l))
		init_newton_two(env->fract);
	else
		return (0);
	set_pallet(env->fract);
	return (1);
}

int				main(int argc, char **argv)
{
	t_env		env;

	if (argc == 1 || (ft_strcmp(argv[1], "julia")
				&& ft_strcmp(argv[1], "mandelbrot")
				&& !ft_strchr("12", argv[1][0])))
	{
		ft_putendl_fd("usage: ./fractol [julia|mandelbroti|1|2]", 2);
		return (0);
	}
	if (!init_env(&env, argv[1][0]))
		return (1);
	fractol_core(&env, env.fract);
	mlx_key_hook(env.win, handle_escape, &env);
	mlx_mouse_hook(env.win, handle_mouse, &env);
	mlx_hook(env.win, 6, 1L >> 0, mouse_motion, &env);
	mlx_loop(env.mlx);
	return (0);
}
