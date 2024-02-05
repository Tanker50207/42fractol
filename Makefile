LIBMLX	:= ./lib/MLX42
CFLAGS= -Wextra -Wall -Werror
LIBS	:= -framework OpenGL -framework IOKit $(LIBMLX)/build/libmlx42.a -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -lm -lft -L./lib/libft
NAME = fractol
OBJECTS = src/main.o src/graphics.o src/compute.o src/mandelbrot.o src/julia.o src/mlxextra.o src/mlx.o src/newton.o
DEPS = -I./include -I $(LIBMLX)/include -I./lib/libft

all: $(LIBMLX) space
	@echo "\033[1;32mMaking libft:\033[0m"
	@$(MAKE) -C ./lib/libft 2>&1 | (grep -v "make\[1\]" || echo "\033[1;33mNothing to be done for libft\033[0m\n")
	@echo "\033[1;32mMaking fractol:\033[0m"
	@$(MAKE) $(NAME) 2>&1 | (grep -v "make\[1\]" || echo "\033[1;33mNothing to be done for fractol\033[0m\n")

$(NAME): $(OBJECTS) include/fractol.h
	@echo
	$(CC) $(OBJECTS) $(LIBS) -o $(NAME) $(CFLAGS)
	@echo "\033[1;32mfractol compiled\033[0m"
	@echo

$(LIBMLX):
	@if [ ! -d /Users/$(USER)/.brew ]; then \
		echo "\033[1;32mInstalling brew:\033[0m"; \
		curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh; \
		echo "\033[1;32mBrew installed\033[0m"; \
	fi
	@if [ ! -d /Users/$(USER)/.brew/opt/glfw ]; then \
		echo "\033[1;32mInstalling glfw:\033[0m"; \
		brew install glfw; \
		echo "\033[1;32mglfw installed\033[0m"; \
	fi
	@if [ ! -d $(LIBMLX) ]; then \
		echo "\033[1;32mMaking libmlx:\033[0m"; \
		git clone https://github.com/Tanker50207/MLX42.git $(LIBMLX); \
		cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4; \
		echo "\033[1;32mMLX42 fetched\033[0m"; \
	fi

clean:
	@rm -f $(OBJECTS)
	@echo "\033[1;31mfractol cleaned\033[0m"

fclean: libclean clean
	@rm -f $(NAME)

libclean:
	@$(MAKE) -C ./lib/libft fclean
	@rm -rf $(LIBMLX)
	@echo "\033[1;31mMLX42 cleaned\033[0m"

re: clean space all

space:
	@echo

%.o: %.c include/fractol.h
	cc -c -o $@ $< $(CFLAGS) $(DEPS)

.PHONY: clean fclean re all libclean space
