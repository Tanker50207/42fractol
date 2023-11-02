/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:14:38 by gcrepin           #+#    #+#             */
/*   Updated: 2023/11/02 14:52:39 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	itterate(t_fractol *fractol)
{
	t_ld	tmp;

	tmp = fractol->zx;
	fractol->zx = (fractol->zx * fractol->zx) - (fractol->zy * fractol->zy)
		+ fractol->cx;
	fractol->zy = (2 * fractol->zy * tmp) + fractol->cy;
}

t_ld	get_absolute(t_fractol *fractol)
{
	return ((fractol->zx * fractol->zx) + (fractol->zy * fractol->zy));
}
