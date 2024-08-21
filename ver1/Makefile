NAME = push_swap.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = -rm -f

SRCS = main.c error_free.c ft_split.c stack_init.c stack_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rsc $(NAME) $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
 