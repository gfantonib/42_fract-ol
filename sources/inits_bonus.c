/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:31:59 by gfantoni          #+#    #+#             */
/*   Updated: 2023/11/17 09:41:59 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot_init(t_fractal *fractal, mlx_t *mlx, mlx_image_t *canvas)
{
	fractal->name = "mandelbrot";
	fractal->f = ft_mandelbrot;
	fractal->iter_max = 100;
	fractal->axis_len = 4.0;
	fractal->trans = fractal->axis_len / SIZE;
	fractal->limit.real = 0.0 - fractal->axis_len / 2.0;
	fractal->limit.i = 0.0 + fractal->axis_len / 2.0;
	fractal->mlx = mlx;
	fractal->canvas = canvas;
	fractal->ch.r = 0;
	fractal->ch.g = 1;
	fractal->ch.b = 2;
}

void	julia_init(t_fractal *fractal, mlx_t *mlx, mlx_image_t *canvas)
{
	fractal->name = "julia";
	fractal->f = ft_julia;
	fractal->iter_max = 100;
	fractal->axis_len = 4.0;
	fractal->trans = fractal->axis_len / SIZE;
	fractal->limit.real = 0.0 - fractal->axis_len / 2.0;
	fractal->limit.i = 0.0 + fractal->axis_len / 2.0;
	fractal->mlx = mlx;
	fractal->canvas = canvas;
	ft_set_julia_const(fractal);
	fractal->ch.r = 0;
	fractal->ch.g = 1;
	fractal->ch.b = 2;
}