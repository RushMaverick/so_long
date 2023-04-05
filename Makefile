NAME = whatever
INC_DIR = includes/
SRC_DIR = src/
MLX_DIR = mlx/
VPATH = src:includes:mlx:gnl:ft_printf:libft
CFLAGS = -Wall -Wextra -Werror -I
MLXFLAGS = -framework OpenGL -framework AppKit
# Sources

SRC_FILES = so_long.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

####
all: $(NAME)

$(NAME): $(SRC)
	make -C $(INC_DIR)
	cc $(CFLAGS) -o $(NAME) $(SRC) -L. $(INC_DIR)/libft.a -L. -lmlx $(MLXFLAGS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
re: fclean all