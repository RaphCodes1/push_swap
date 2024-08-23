NAME = push_swap.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = -rm -f

SRCS = main.c error_free.c ft_split.c stack_init.c stack_utils.c \
		rotate_cmd.c push_cmd.c rev_rotate_cmd.c swap_cmd.c \
		tiny_sort.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rsc $(NAME) $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
 