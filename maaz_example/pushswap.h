/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:56:01 by maakhan           #+#    #+#             */
/*   Updated: 2024/08/13 15:49:03 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_list
{
	int				content;
	int				index_to_top;
	struct t_list	*next;
}					t_stack;

// libft
int					ft_abs(int num);
int					ft_strlen(const char *s);
char				**ft_split(const char *s, char c);
int					ft_word_count(const char *s, char sep);
char				*ft_atol_modified(char *str, long long *number);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
int					ft_memcmp(const void *s1, const void *s2, int n);

// t_stack_utils_
t_stack				*t_stack_new(int number);
t_stack				*last_block(t_stack *a);
void				t_stack_add(t_stack **a, t_stack *new_block);
int					t_stack_len(t_stack *a);
char				*t_stack_init(t_stack **a, char **strings, int len);

// instruct utils
void				swap(t_stack **a);
void				push(t_stack **a, t_stack **b);
void				rotate(t_stack **top);
void				reverse_rotate(t_stack **top);

// instructions
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **b, t_stack **a);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

// sorting functions
t_stack				*find_max_block(t_stack *a);
t_stack				*find_min_block(t_stack *a);
void				push_elements_to_b(t_stack **b, t_stack **a);
void				tiny_sort(t_stack **a);
void				final_sort(t_stack **a);
t_stack				*target_block(t_stack *element, t_stack *s, char t_stacks);
t_stack				*cheapest_block(t_stack *a, t_stack *b);
int					index_to_top(t_stack *element, t_stack *s);
int					push_cost(t_stack *a, t_stack *b, t_stack *element,
						t_stack *target);
void				sorting(t_stack **a, t_stack **b);
int					is_sorted(t_stack *a, t_stack *b);

// pushing cheapest element to top
void				push_cheapest_element(t_stack **a, t_stack **b);
void				elements_to_top(t_stack *cheapest, t_stack *target,
						t_stack **a, t_stack **b);
void				rotate_ab(t_stack **a, t_stack **b, t_stack *cheapest,
						t_stack *target);
void				reverse_rotate_ab(t_stack **a, t_stack **b,
						t_stack *cheapest, t_stack *target);
void				rotate_a(t_stack **a, t_stack *target);
void				reverse_rotate_a(t_stack **a, t_stack *target);
void				rotate_b(t_stack **b, t_stack *cheapest);
void				reverse_rotate_b(t_stack **b, t_stack *cheapest);

// Errors
char				*repetition_error(t_stack **a, long number);
int					error_msg(t_stack **a, t_stack **b);
int					space_only(char *s);

// parsing
void				t_stack_clear(t_stack **a);
void				free_strings(char *big_arg, char **nums);
char				*arg_join(int argc, char **argv);
char				*parsing(t_stack **a, int argc, char **argv);

// bonus
int					error_msg_bonus(t_stack **a, t_stack **b, char *instruct);
void				sa_checker(t_stack **a);
void				sb_checker(t_stack **b);
void				ss_checker(t_stack **a, t_stack **b);
void				pa_checker(t_stack **a, t_stack **b);
void				pb_checker(t_stack **b, t_stack **a);
void				ra_checker(t_stack **a);
void				rb_checker(t_stack **b);
void				rr_checker(t_stack **a, t_stack **b);
void				rra_checker(t_stack **a);
void				rrb_checker(t_stack **b);
void				rrr_checker(t_stack **a, t_stack **b);

void				t_stack_clear(t_stack **a);

#endif