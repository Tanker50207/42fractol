/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:58:02 by gcrepin           #+#    #+#             */
/*   Updated: 2023/11/02 17:12:30 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_error(void)
{
	ft_printf("%s\n", mlx_strerror(mlx_errno));
	error_message();
	exit(EXIT_FAILURE);
}

static void	ft_key_hook(mlx_key_data_t keycode, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (keycode.key == MLX_KEY_ESCAPE)
	{
		mlx_terminate(fractol->mlx);
		exit(EXIT_SUCCESS);
	}
	if (keycode.key == MLX_KEY_RIGHT)
		fractol->x_mod += fractol->scale / 4;
	else if (keycode.key == MLX_KEY_LEFT)
		fractol->x_mod -= fractol->scale / 4;
	else if (keycode.key == MLX_KEY_UP)
		fractol->y_mod -= fractol->scale / 4;
	else if (keycode.key == MLX_KEY_DOWN)
		fractol->y_mod += fractol->scale / 4;
	else if (keycode.key == MLX_KEY_P)
		fractol->iter_default += 10;
	else if (keycode.key == MLX_KEY_M)
		fractol->iter_default -= 10;
	else if (keycode.key == MLX_KEY_T)
		fractol->iter_default = 500;
	else
		return ;
	fractol->current(*fractol);
}

static void	ft_scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;
	int			mouse_x;
	int			mouse_y;

	(void) xdelta;
	fractol = (t_fractol *)param;
	mlx_get_mouse_pos(fractol->mlx, &mouse_x, &mouse_y);
	if (ydelta < 0)
	{
		fractol->scale *= 1.5;
		fractol->iter_default -= 15;
	}
	else
	{
		fractol->scale /= 1.5;
		fractol->iter_default += 15;
	}
	fractol->x_mod += (fractol->scale
			* (((t_ld)(2 * mouse_x) - (t_ld)fractol->mlx->width)
				/ (t_ld)fractol->mlx->height)) / 2;
	fractol->y_mod += (fractol->scale * (((t_ld)(2 * mouse_y)
					/ (t_ld)fractol->mlx->height) - 1)) / 2;
	fractol->current(*fractol);
}

t_fractol	innit_fractol(t_fractol fractol, mlx_t *mlx,
		mlx_image_t *img, char *fractal)
{
	fractol.mlx = mlx;
	fractol.img = img;
	fractol.scale = 2;
	fractol.x_mod = 0;
	fractol.y_mod = 0;
	fractol.iter_default = 100;
	if (ft_strcmp(fractal, "mandelbrot") == 0)
		fractol.current = mandelbrot;
	else if (ft_strcmp(fractal, "julia") == 0)
		fractol.current = julia;
	else
		ft_error();
	return (fractol);
}

void	start(char *fractal, char preset)
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	static t_fractol	fractol;

	mlx = mlx_init(2560, 1440, "Fractol", false);
	if (!mlx)
		ft_error();
	img = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	fractol = innit_fractol(fractol, mlx, img, fractal);
	if (ft_strcmp(fractal, "julia") == 0)
		fractol = set_julia_c_preset(fractol, preset);
	fractol.current(fractol);
	mlx_key_hook(mlx, ft_key_hook, &fractol);
	mlx_scroll_hook(mlx, ft_scroll_hook, &fractol);
	mlx_mouse_hook(mlx, ft_on_click, &fractol);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
