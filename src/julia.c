/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:02:10 by gcrepin           #+#    #+#             */
/*   Updated: 2023/11/03 12:41:51 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_fractol	reset_fractol(t_fractol fractol, int x, int y)
{
	fractol.max_iter = fractol.iter_default;
	fractol.zx = (fractol.scale
			* (((t_ld)(2 * x) - (t_ld)fractol.mlx->width)
				/ (t_ld)fractol.mlx->height)) + fractol.x_mod;
	fractol.zy = (fractol.scale * (((t_ld)(2 * y)
					/ (t_ld)fractol.mlx->height) - 1)) + fractol.y_mod;
	return (fractol);
}

void	print_julia_seed(t_fractol fractol)
{
	char	*tmp;
	size_t	i;

	ft_printf("Julia seed: ");
	if (fractol.cx < 0 && fractol.cx > -1)
		ft_putchar('-');
	ft_printf("%d.", (int)(fractol.cx));
	tmp = ft_itoa((int)fabsl(((fractol.cx - (int)fractol.cx) * 1000000)));
	i = 0;
	while (i++ < 6 - ft_strlen(tmp))
		ft_putchar('0');
	ft_printf("%s", tmp);
	free(tmp);
	ft_putstr(" + ");
	if (fractol.cy < 0 && fractol.cy > -1)
		ft_putchar('-');
	ft_printf("%d.", (int)(fractol.cy));
	tmp = ft_itoa((int)fabsl(((fractol.cy - (int)fractol.cy) * 1000000)));
	i = 0;
	while (i++ < 6 - ft_strlen(tmp))
		ft_putchar('0');
	ft_printf("%s", tmp);
	free(tmp);
	ft_putstr("i\n");
}

t_fractol	set_julia_c(t_fractol fractol, int x, int y)
{
	fractol.cx = (fractol.scale
			* (((t_ld)(2 * x) - (t_ld)fractol.mlx->width)
				/ (t_ld)fractol.mlx->height));
	fractol.cy = (fractol.scale * (((t_ld)(2 * y)
					/ (t_ld)fractol.mlx->height) - 1));
	print_julia_seed(fractol);
	return (fractol);
}

t_fractol	set_julia_c_preset(t_fractol fractol, char preset)
{
	if (preset == '1')
	{
		fractol.cx = 0.355;
		fractol.cy = 0.355;
	}
	else if (preset == '2')
	{
		fractol.cx = -0.54;
		fractol.cy = 0.54;
	}
	else if (preset == '3')
	{
		fractol.cx = 0.37;
		fractol.cy = 0.1;
	}
	else if (preset == '4')
	{
		fractol.cx = -0.744444;
		fractol.cy = -0.105555;
	}
	print_julia_seed(fractol);
	return (fractol);
}

void	julia(t_fractol fractol)
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
				iterate(&fractol);
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
