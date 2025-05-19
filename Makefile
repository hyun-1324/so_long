NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes/ -I./MLX42/include -Wunreachable-code -Ofast -MMD -MP
RM = rm -f

SRCS_PATH = ./src
OBJS_PATH = ./obj
LIBFT_PATH = ./libft
MLX_PATH = ./MLX42

MLXLIB = $(MLX_PATH)/build/libmlx42.a
LIBFT = $(LIBFT_PATH)/libft.a
SRCS = $(SRCS_PATH)/so_long.c \
		$(SRCS_PATH)/map_validation.c \

OBJS = $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)
DEP = $(OBJS:.o=.d)

.SECONDARY: $(OBJS)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXLIB) $(LDFLAGS) -o $(NAME)

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEP)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

clean :
	@rm -rf $(OBJS_PATH)
	@rm -f $(DEP)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re : fclean all

.PHONY : all clean fclean re bonus
