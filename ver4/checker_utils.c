#include "get_next_line/get_next_line.h"
#include "push_swap.h"

void stack_init_checker(t_stack_node **a, char **av, bool flag_ac_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{	
		if (error_syntax(av[i]))
			error_free_checker(a, av, flag_ac_2);
		nbr = ft_atol(av[i]);
		if ((nbr > INT_MAX || nbr < INT_MIN) || !(error_repetition(*a, (int)nbr)))
			error_free_checker(a, av, flag_ac_2);
		append_node(a, (int)nbr);
		i++;
	}
	if (flag_ac_2)
		free_matrix(av);
}

void error_free_checker(t_stack_node **stack, char **av, bool flag_ac_2)
{
	free_stack(stack);
	if (flag_ac_2)
		free_matrix(av);
    write(2, "Error\n", 6);
    exit(1);
}