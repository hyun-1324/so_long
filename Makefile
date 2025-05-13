NAME = so_long

SRCS =

OBJS = $(SRCS:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

.SECONDARY: $(OBJS)

all : $(NAME)

$(NAME) : $(MLX_DIR)/libmlx.a libft/libft.a
	$(NAME): $(OBJS) mlx/libmlx.a libft/libft.a -o $@

%.o : %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
