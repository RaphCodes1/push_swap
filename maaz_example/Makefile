NAME = push_swap
NAME_BONUS = checker

REM		=	rm -rf

SRCS =	instructs/instructs_for_a.c instructs/instructs_for_b.c instructs/instructs_for_both.c instructs/instruct_utils.c \
		libft/ft_abs.c libft/ft_atol_modified.c libft/ft_split.c libft/ft_strjoin.c libft/ft_strdup.c libft/ft_strlen.c libft/ft_memcmp.c \
		push_cheapest/push_cheapest.c push_cheapest/push_cheapest_utils.c \
		sorting/block_utils.c sorting/sorting_utils.c sorting/sorting.c sorting/target_block.c \
		errors.c stack_utils.c \
		parsing.c \
		main.c \

SRCS_BONUS =	instructs/instructs_for_a.c instructs/instructs_for_b.c instructs/instructs_for_both.c instructs/instruct_utils.c \
				libft/ft_abs.c libft/ft_atol_modified.c libft/ft_split.c libft/ft_strjoin.c libft/ft_strdup.c libft/ft_strlen.c libft/ft_memcmp.c \
				push_cheapest/push_cheapest.c push_cheapest/push_cheapest_utils.c \
				sorting/block_utils.c sorting/sorting_utils.c sorting/sorting.c sorting/target_block.c \
				errors.c stack_utils.c \
				parsing.c \
				errors_bonus.c instructs/instructs_for_a_bonus.c instructs/instructs_for_b_bonus.c instructs/instructs_for_both_bonus.c \
				get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
				checker.c \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

bonus : $(NAME) $(NAME_BONUS)

$(NAME): $(OBJS)
	cc $(CFLAGS) $^ -o $@

$(NAME_BONUS): $(OBJS_BONUS)
	cc $(CFLAGS)  $^ -o $@

%.o:%.c
	cc -c $(CFLAGS) $< -o $@

clean: 
	$(REM) $(OBJS)
	# $(REM) $(OBJS_BONUS)

fclean: 
	$(REM) $(OBJS) $(OBJS_BONUS)
	# $(REM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus