NAME = push_swap
NAME_BONUS = checker

CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = -rm -f

SRCS = main.c error_free.c ft_split.c stack_init.c stack_utils.c \
		rotate_cmd.c push_cmd.c rev_rotate_cmd.c swap_cmd.c \
		tiny_sort.c push_swap_init.c push_swap_cmd.c split_modif.c 

SRCS_BONUS = checker.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)
bonus: $(NAME) $(NAME_BONUS)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(NAME_BONUS):$(filter-out main.o,$(OBJS)) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
 