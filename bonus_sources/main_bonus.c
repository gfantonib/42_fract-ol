/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:26:50 by gfantoni          #+#    #+#             */
/*   Updated: 2023/11/20 16:13:01 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_fractol.h"

void	ft_classic_artist(void *param)
{
	t_fractal	*fr;
	t_point		a;
	t_point		b;
	t_point		c;
	int			n;
	
	fr = param;
	a = fr->pinsky.a;
	b = fr->pinsky.b;
	c = fr->pinsky.c;
	n = fr->iter_max;
	ft_sierpinsky(a, b, c, n, fr);
}

void	ft_artist(void *param)
{
	t_fractal	*fractal;
	uint32_t	color;
	t_complex	c;
	uint32_t	w;
	uint32_t	h;

	w = 0;
	fractal = param;
	while (w < fractal->canvas->width)
	{
		h = 0;
		while (h < fractal->canvas->height)
		{
			ft_trans(&c, fractal, w, h);
			color = fractal->f(fractal, &c);
			mlx_put_pixel(fractal->canvas, w, h, color);
			h++;
		}
		w++;
	}
}

int32_t	main(int32_t argc, const char **argv)
{
	t_fractal		fractal;
	int				error;
	
	error = ft_check_error(argc, argv, &fractal);
	if (error)
	{
		puts("usage: ./fractol_bonus mandelbrot OR ./fractal_bonus julia {a..d} OR ./fractal_bonus sierpinsky");
		return (EXIT_FAILURE);
	}
	error = ft_render(&fractal, argv[1]);
	if (error)
		return (EXIT_FAILURE);
	
	if (!ft_strcmp(argv[1], "sierpinsky"))
		mlx_loop_hook(fractal.mlx, ft_classic_artist, &fractal);
	else
		mlx_loop_hook(fractal.mlx, ft_artist, &fractal);
	mlx_scroll_hook(fractal.mlx, ft_zoom, &fractal);
	mlx_loop_hook(fractal.mlx, ft_joystick, &fractal);
	mlx_loop(fractal.mlx);
	mlx_terminate(fractal.mlx);
	return (EXIT_SUCCESS);
}
