NAME = whatever
INC_DIR = includes
SRC_DIR = src
MLX_DIR = mlx
VPATH = src:includes:mlx:gnl:ft_printf:libft
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework AppKit
# Sources

SRC_FILES = main.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

####
all: $(NAME)

$(NAME): $(SRC)
	make -C $(INC_DIR)
	make -C $(MLX_DIR)
	cc $(CFLAGS) $(SRC) -o $(NAME) -L. $(INC_DIR)/libft.a -L. -lmlx $(MLXFLAGS)

clean:
	rm -rf $(INC_DIR)/libft.a
	rm -rf $(MLX_DIR)/libmlx.a

fclean: clean
	make fclean -C $(INC_DIR)
	rm -f $(NAME)
re: fclean all