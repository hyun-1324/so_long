
NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

SRCS_PATH = src
LIBFT_PATH = libft
LIBMLX = ./MLX42


HEADERS = -I $(LIBMLX)/include
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

MLXLIB = $(MLX_PATH)/build/libmlx42.a
LIBFT = $(LIBFT_PATH)/libft.a
SRCS = $(SRCS_PATH)/so_long.c \
	   $(SRCS_PATH)/map_validation.c \
	   $(SRCS_PATH)/check_chars.c \
	   $(SRCS_PATH)/check_paths.c \
	   $(SRCS_PATH)/get_next_line.c \
	   $(SRCS_PATH)/map_utils.c \
	   $(SRCS_PATH)/game.c \
	   $(SRCS_PATH)/game_utils.c \

OBJS = $(SRCS:.c=.o)
LIBFT = $(LIBFT_PATH)/libft.a

.SECONDARY: $(OBJS)

all : libmlx $(LIBFT) $(NAME)

libmlx: $(LIBMLX)
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBMLX):
	@git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX)

$(SRCS_PATH)/%.o: $(SRCS_PATH)/%.c
	$(CC) $(CFLAGS) -c $< $(HEADERS) -o $@

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(LIBS) $(HEADERS) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean :
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make clean -C $(LIBFT_PATH)

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(LIBMLX)
	@make fclean -C $(LIBFT_PATH)

re : fclean all

.PHONY : all clean fclean re bonus
