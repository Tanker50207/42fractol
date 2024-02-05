/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:42:34 by gcrepin           #+#    #+#             */
/*   Updated: 2023/11/06 13:47:22 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	iterate_n(t_fractol *fractol)
{
	t_ld	tmp;

	tmp = fractol->zx;
	fractol->zx = (fractol->zx * fractol->zx * fractol->zx)
		- (3 * fractol->zx * fractol->zy * fractol->zy) + fractol->cx;
	fractol->zy = (3 * tmp * tmp * fractol->zy)
		- (fractol->zy * fractol->zy * fractol->zy) + fractol->cy;
}

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

void	newton(t_fractol fractol)
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
				iterate_n(&fractol);
			if (fractol.max_iter > 0)
				ft_put_pixel(fractol, x, y);
			else
				mlx_put_pixel(fractol.img, x, y,
					create_trgb(255, 0, 0, 0));
			y++;
		}
		x++;
	}
}
