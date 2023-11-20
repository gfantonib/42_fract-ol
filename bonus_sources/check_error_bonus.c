/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:33:08 by gfantoni          #+#    #+#             */
/*   Updated: 2023/11/17 12:52:01 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_check_error(int argc, const char **argv, t_fractal *fractal)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
	{
		fractal->init = mandelbrot_init;
		return (0);
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "julia", 5))
	{
		fractal->julia_c = 'S';
		fractal->init = julia_init;
		return (0);
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "sierpinsky", 10))
	{
		fractal->init = sierpinsky_init;
		return (0);
	}
	if (argc == 3 && !ft_strncmp(argv[1], "julia", 5) && 
		argv[2][0] >= 'a' && argv[2][0] <= 'd')
	{
		fractal->julia_c = argv[2][0];
		fractal->init = julia_init;
		return (0);
	}
	return (1);
}