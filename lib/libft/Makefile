CFLAGS= -Wextra -Wall -Werror
DEPS = libft.h
NAME = libft.a
OBJECTS = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_strcmp.o ft_memmove.o ft_memset.o ft_putchar_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_split.o ft_strchr.o ft_strdup.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strmapi.o ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_strtrim.o ft_substr.o ft_tolower.o ft_toupper.o ft_lstadd_back.o ft_lstadd_front.o ft_lstclear.o ft_lstdelone.o ft_lstiter.o ft_lstlast.o ft_lstmap.o ft_lstnew.o ft_lstsize.o ft_strcat.o ft_strmap.o ft_striter.o
FT_PRINTF_OBJ = additions/ft_printf/ft_printf.o additions/ft_printf/ft_parse.o additions/ft_printf/ft_put001.o additions/ft_printf/ft_put002.o
GET_NEXT_LINE_OBJ = additions/get_next_line/get_next_line.o

all: $(NAME)

$(NAME): $(OBJECTS) $(FT_PRINTF_OBJ) $(GET_NEXT_LINE_OBJ)
	ar -rscu $(NAME) $(OBJECTS) $(FT_PRINTF_OBJ) $(GET_NEXT_LINE_OBJ)
	@echo "\033[1;32mlibft.a created\033[1;32m\n"

clean:
	@rm -f $(OBJECTS) $(FT_PRINTF_OBJ) $(GET_NEXT_LINE_OBJ)
	@echo "\033[1;31mlibft cleaned\033[1;0m"

fclean: clean
	@rm -f $(NAME)

re: fclean all

additions/ft_printf/%.o: additions/ft_printf/%.c $(DEPS) additions/ft_printf/libftprintf.h
	cc -c -o $@ $< $(CFLAGS) -I.

additions/get_next_line/%.o: additions/get_next_line/%.c additions/get_next_line/get_next_line.h
	cc -c -o $@ $< $(CFLAGS) -I.

%.o: %.c $(DEPS)
	cc -c -o $@ $< $(CFLAGS) -I.

.PHONY: clean fclean re all
