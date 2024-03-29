/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:17:25 by gcrepin           #+#    #+#             */
/*   Updated: 2023/11/09 12:53:32 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_message(void)
{
	ft_printf("\nUsage: ./fractol mandelbrot\n");
	ft_printf("Usage: ./fractol newton\n");
	ft_printf("Usage: ./fractol julia [preset]\n\n");
	ft_printf("The julia presets are 1, 2, 3 and 4\n");
	ft_printf("Any other argument or no argument will result in");
	ft_printf(" the julia set for complex number 0 + 0i\n\n");
	ft_printf("Mandelbrot: z = z^2 + c	where z is 0 and c is the pixel pos\n");
	ft_printf("Julia: z = z^2 + c	where z is the pixel pos and c is seed\n");
	ft_printf("Newton: z = z^3 + c	where z is 0 and c is the pixel pos\n\n");
	ft_printf("Press P to increase the number of iterations\n");
	ft_printf("Press M to decrease the number of iterations\n");
	ft_printf("Press R to reset the view\n");
	ft_printf("Press the arrow keys to move around\n");
	ft_printf("Scroll up to zoom in\n");
	ft_printf("Scroll down to zoom out\n");
	ft_printf("Click to change to the julia set using your mouse position");
	ft_printf(" as the seed\n");
	ft_printf("Press ESC to exit\n\n");
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		error_message();
		return (0);
	}
	if (ft_strcmp(argv[1], "mandelbrot") == 0 && argc == 2)
		start("mandelbrot", 0);
	else if (ft_strcmp(argv[1], "newton") == 0 && argc == 2)
		start("newton", 0);
	else if (ft_strcmp(argv[1], "julia") == 0 && argc >= 2)
	{
		if (argc == 3)
			start("julia", argv[2][0]);
		else
			start("julia", 0);
	}
	else
		error_message();
}
