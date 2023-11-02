/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:59:34 by gcrepin           #+#    #+#             */
/*   Updated: 2023/11/02 17:15:57 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static t_fractol	reset_fractol(t_fractol fractol, int x, int y)
{
	fractol.max_iter = fractol.iter_default;
	fractol.cx = (fractol.scale
			* (((t_ld)(2 * x) - (t_ld)fractol.mlx->width)
				/ (t_ld)fractol.mlx->height)) + fractol.x_mod;
	fractol.cy = (fractol.scale * (((t_ld)(2 * y)
					/ (t_ld)fractol.mlx->height) - 1)) + fractol.y_mod;
	fractol.zx = 0;
	fractol.zy = 0;
	return (fractol);
}

void	mandelbrot(t_fractol fractol)
{
	int	x;
	int	y;

	x = 0;
	while (x < fractol.mlx->width)
	{
		y = 0;
		while (y < fractol.mlx->height)
		{
			fractol = reset_fractol(fractol, x, y);
			while (get_absolute(&fractol) < 4 && fractol.max_iter-- > 0)
				itterate(&fractol);
			if (fractol.max_iter > 0)
				mlx_put_pixel(fractol.img, x, y,
					create_trgb(255, 0,
						255 - ((255 * fractol.max_iter)
							/ (fractol.iter_default * 1.5)),
						(255 * fractol.max_iter) / (fractol.iter_default * 2)));
			else
				mlx_put_pixel(fractol.img, x, y,
					create_trgb(255, 0, 0, 0));
			y++;
		}
		x++;
	}
}
