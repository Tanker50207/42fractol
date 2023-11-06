/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:29:08 by gcrepin           #+#    #+#             */
/*   Updated: 2023/11/03 12:30:32 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/MLX42.h"
# include "libft.h"
# include <math.h>

typedef long double	t_ld;
typedef struct s_fractol
{
	t_ld		zx;
	t_ld		zy;
	int			max_iter;
	t_ld		cx;
	t_ld		cy;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_ld		scale;
	t_ld		x_mod;
	t_ld		y_mod;
	int			iter_default;
	int			re_do;
	void		(*current)(struct s_fractol);
}				t_fractol;

int			create_trgb(int t, int r, int g, int b);
void		mandelbrot(t_fractol fractol);
t_ld		get_absolute(t_fractol *fractol);
void		iterate(t_fractol *fractol);
void		julia(t_fractol fractol);
void		ft_on_click(mouse_key_t button, action_t action, modifier_key_t mod,
				void *param);
t_fractol	set_julia_c(t_fractol fractol, int x, int y);
t_fractol	set_julia_c_preset(t_fractol fractol, char preset);
void		start(char *fractal, char preset);
void		error_message(void);
t_fractol	innit_fractol(t_fractol fractol, mlx_t *mlx,
				mlx_image_t *img, char *fractal);
void		reset_view(t_fractol *fractol);
void		ft_put_pixel(t_fractol fractol, int x, int y);
void		ft_loop_hook(void *param);
void		newton(t_fractol fractol);

#endif
