/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onclick.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:07:36 by gcrepin           #+#    #+#             */
/*   Updated: 2023/11/02 15:41:58 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_on_click(mouse_key_t button, action_t action, modifier_key_t mod,
	void *param)
{
	t_fractol	*fractol;
	int			mouse_x;
	int			mouse_y;

	(void)mod;
	fractol = param;
	if (button != MLX_MOUSE_BUTTON_LEFT || action != MLX_PRESS)
		return ;
	mlx_get_mouse_pos(fractol->mlx, &mouse_x, &mouse_y);
	*fractol = innit_fractol(*fractol, fractol->mlx, fractol->img, "julia");
	fractol->current = julia;
	*fractol = set_julia_c(*fractol, mouse_x, mouse_y);
	julia(*fractol);
}
