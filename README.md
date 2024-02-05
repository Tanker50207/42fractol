42 Fractol

Made for 42 macs, not responsible if it doesn't work on your device, you'll have to fight the Makefile yourself. Probably the compile flags will be the problem so find the frameworks that work for your device.
The Makefile will attempt to install 42homebrew, cmake and glfw. Do it manually and remove those steps from Makefile if it causes problems.
Uses my fork of mlx42: https://github.com/Tanker50207/MLX42 (that's the thing that you will have to fight the Makefile for)
refer to that page if needed


run make to compile



Usage: ./fractol mandelbrot

Usage: ./fractol newton

Usage: ./fractol julia [preset]


The julia presets are 1, 2, 3 and 4

Any other argument or no argument will result in the julia set for complex number 0 + 0i


Mandelbrot: z = z^2 + c where z is 0 and c is the pixel pos

Julia: z = z^2 + c      where z is the pixel pos and c is seed

Newton: z = z^3 + c     where z is 0 and c is the pixel pos


Press P to increase the number of iterations

Press M to decrease the number of iterations

Press R to reset the view

Press the arrow keys to move around

Scroll up to zoom in

Scroll down to zoom out

Click to change to the julia set using your mouse position as the seed

Press ESC to exit
