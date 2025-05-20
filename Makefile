
NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBMLX = ./MLX42
LIBFT = libft/libft.a

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



OBJS = $(SRCS:$(SRCS_PATH)/%.c=$(SRCS_PATH)/%.o)

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
	@make -C ./libft

clean :
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make clean -C ./libft

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(LIBMLX)
	@make fclean -C ./libft

re : fclean all

.PHONY : all clean fclean re bonus




# NAME = so_long

# CC = cc
# CFLAGS = -Wall -Wextra -Werror -g -I./includes/ -I./MLX42/include -Wunreachable-code -Ofast -MMD -MP
# LDFLAGS = -ldl -lglfw -pthread -lm
# RM = rm -f

# SRCS_PATH = ./src
# OBJS_PATH = ./obj
# LIBFT_PATH = ./libft
# MLX_PATH = ./MLX42

# MLXLIB = $(MLX_PATH)/build/libmlx42.a
# LIBFT = $(LIBFT_PATH)/libft.a
# SRCS = $(SRCS_PATH)/so_long.c \
# 	   $(SRCS_PATH)/map_validation.c \
# 	   $(SRCS_PATH)/check_chars.c \
# 	   $(SRCS_PATH)/check_paths.c \
# 	   $(SRCS_PATH)/get_next_line.c \
# 	   $(SRCS_PATH)/map_utils.c \
# 	   $(SRCS_PATH)/game.c \
# 	   $(SRCS_PATH)/game_utils.c \



# OBJS = $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)
# DEP = $(OBJS:.o=.d)

# .SECONDARY: $(OBJS)

# all : $(NAME)

# $(NAME) : $(OBJS) $(LIBFT)
# 	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXLIB) $(LDFLAGS) -o $(NAME)

# $(OBJS_PATH):
# 	mkdir -p $(OBJS_PATH)

# $(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
# 	$(CC) $(CFLAGS) -c $< -o $@

# -include $(DEP)

# $(LIBFT):
# 	@$(MAKE) -C $(LIBFT_PATH)

# clean :
# 	@rm -rf $(OBJS_PATH)
# 	@rm -f $(DEP)
# 	@$(MAKE) -C $(LIBFT_PATH) clean

# fclean : clean
# 	@rm -f $(NAME)
# 	@$(MAKE) -C $(LIBFT_PATH) fclean

# re : fclean all

# .PHONY : all clean fclean re bonus
