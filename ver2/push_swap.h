#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack_node
{
    int value;
    int current_position;
    int push_price;
    bool above_median;
    bool cheapest;
    struct s_stack_node *target_node;
    struct s_stack_node *next;
    struct s_stack_node *prev;
}   t_stack_node;


char **ft_split(char *s, char c);

void free_matrix(char **av);
void free_stack(t_stack_node **stack);
void error_free(t_stack_node **stack, char **av, bool flag_ac_2);
int error_repetition(t_stack_node *a, int nbr);
int error_syntax(char *s);

void set_target_node(t_stack_node *a, t_stack_node *b);
void stack_init(t_stack_node **a, char **av, bool flag_ac_2);
void init_nodes(t_stack_node *a, t_stack_node *b);
void current_pos(t_stack_node *stack);
void set_price(t_stack_node *a, t_stack_node *b);
void set_cheapest(t_stack_node *b);

void append_node(t_stack_node **stack,int nbr);
t_stack_node *find_last_node(t_stack_node *node);
t_stack_node *find_highest(t_stack_node *stack);
t_stack_node *find_smallest(t_stack_node *stack);
t_stack_node *return_cheapest(t_stack_node *b);
bool stack_sorted(t_stack_node *stack);
int stack_len(t_stack_node *stack);
void finish_rotation(t_stack_node **stack, t_stack_node *top_node, char c);

void tiny_sort(t_stack_node **stack);
void push_swap(t_stack_node **a, t_stack_node **b);
void handle_five(t_stack_node **a, t_stack_node **b);

void sa(t_stack_node **a, bool checker);
void sb(t_stack_node **b, bool checker);
void ss(t_stack_node **a, t_stack_node **b, bool checker);
void ra(t_stack_node **a, bool checker);
void rb(t_stack_node **b, bool checker);
void rr(t_stack_node **a, t_stack_node **b, bool checker);
void rra(t_stack_node **a, bool checker);
void rrb(t_stack_node **b, bool checker);
void rrr(t_stack_node **a, t_stack_node **b, bool checker);
void pa(t_stack_node **a, t_stack_node **b, bool checker);
void pb(t_stack_node **a, t_stack_node **b, bool checker);

char *split_modif(char **s);
char **ft_splitver2(char const *s, char c);

#endif