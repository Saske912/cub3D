NAME = cub3D
OBJ = init.o \
	hook.o \
	step.o \
	get_next_line_utils.o \
	get_next_line.o \
	ft.o \
	get.o \
	get_map.o \
	error.o \
	check.o \
	path.o \
	valid.o \
	init_struct.o \
	make.o \
	main.o \
	print.o \
	print_map.o \
	add.o \
	init_map.o \
	find.o \
	sort.o \
	display.o \
	save.o

HEADER = cub3D.h structs.h funcs.h defines.h
LIBFT = libft.a
MLX = libmlx.dylib
FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft/
MLX_DIR = mlx/
LIBS = $(LIBFT) $(MLX)

all: $(NAME)

$(NAME): $(OBJ)
	make bonus -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	mv $(LIBFT_DIR)$(LIBFT) $(MLX_DIR)$(MLX) .
	gcc -g $(OBJ) $(LIBS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ) mlx/*.o libft/*.o $(LIBS)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

bonus: all

.PHONY: all clean fclean re
