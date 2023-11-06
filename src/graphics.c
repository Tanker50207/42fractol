/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:14:41 by gcrepin           #+#    #+#             */
/*   Updated: 2023/11/06 11:39:29 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | t);
}

void	ft_put_pixel(t_fractol fractol, int x, int y)
{
	int	red;
	int	green;
	int	blue;

	if (((fractol.iter_default - fractol.max_iter) / 100) % 2)
	{
		red = 255 * (fractol.iter_default - fractol.max_iter)
			/ (fractol.iter_default);
		green = 0;
	}
	else
	{
		red = 0;
		green = 255 * (fractol.iter_default - fractol.max_iter)
			/ (fractol.iter_default);
	}
	blue = 122 * fractol.max_iter / fractol.iter_default;
	mlx_put_pixel(fractol.img, x, y, create_trgb(255, red, green, blue));
}
