LIBMLX	:= ./lib/MLX42
CFLAGS= -Wextra -Wall -Werror -g
LIBS	:= -framework OpenGL -framework IOKit $(LIBMLX)/build/libmlx42.a -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -lm -lft -L./lib/libft
NAME = fractol
OBJECTS = src/main.o src/graphics.o src/compute.o src/mandelbrot.o src/julia.o src/onclick.o src/mlx.o
DEPS = -I./include -I $(LIBMLX)/include -I./lib/libft

all: $(LIBMLX)/build/libmlx42.a
	@echo "\033[1;32mMaking libft:\033[0m"
	@$(MAKE) -C ./lib/libft 2>&1 | (grep -v "make\[1\]" || echo "\033[1;33mNothing to be done for libft\033[0m\n")
	@echo "\033[1;32mMaking fractol:\033[0m"
	@$(MAKE) $(NAME) 2>&1 | (grep -v "make\[1\]" || echo "\033[1;33mNothing to be done for fractol\033[0m\n")

$(NAME): $(OBJECTS) include/fractol.h
	@echo
	$(CC) $(OBJECTS) $(LIBS) -o $(NAME) $(CFLAGS)
	@echo "\033[1;32mfractol compiled\033[0m"
	@echo

$(LIBMLX)/build/libmlx42.a:
	@echo "\033[1;32mMaking libmlx:\033[0m"
	@git fetch https://github.com/Tanker50207/MLX42.git
	@Cmake -S $(LIBMLX) -B $(LIBMLX)/build
	@echo "\033[1;32mMLX42 fetched\033[0m"

clean:
	@rm -f $(OBJECTS)
	@echo "\033[1;31mfractol cleaned\033[0m"

fclean: libclean clean
	@rm -f $(NAME)

libclean:
	@$(MAKE) -C ./lib/libft fclean

re: fclean space all

space:
	@echo

%.o: %.c
	cc -c -o $@ $< $(CFLAGS) $(DEPS)

.PHONY: clean fclean re all libclean space
