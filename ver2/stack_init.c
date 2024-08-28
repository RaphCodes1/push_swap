#include "push_swap.h"

static long ft_atol(char *s)
{
    int conv;
    long res;
    int i;

    res = 0;
    conv = 1;
    i = 0;

    while(s[i] == ' ' ||(s[i] >= 9 && s[i] <= 13))
        i++;
    if(s[i] == '+' || s[i] == '-')
    {
        if(s[i] == '-')
            conv *= -1;
        i++;
    }
    while(s[i] >= '0' && s[i] <= '9')
    {
        res = res * 10 + (s[i] - '0');
        i++;
    }
    return (res * conv);
}

void stack_init(t_stack_node **a, char **av, bool flag_ac_2)
{
    long nbr;
    int i;

    i = 0;
    while(av[i])
    {   
        if(error_syntax(av[i]))
            error_free(a,av,flag_ac_2);
        nbr = ft_atol(av[i]);
        if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, av, flag_ac_2);
        if(!error_repetition(*a, (int)nbr))
            error_free(a,av,flag_ac_2);
        append_node(a, (int)nbr);
        i++;
    }
    if(flag_ac_2)
        free_matrix(av);

}
// int main()
// {
//     t_stack_node *a;
//     a = NULL;

//     char *str = "42 11111111111111111111111111111111111111111111111111111111111111111111111 -42";
//     char **test = (char **)malloc(sizeof(char *) * (4 + 1));
//     test = ft_split(str,' ');
//     int i = 0;
//     while(test[i])
//         printf("list: %s\n",test[i++]);

//     stack_init(&a,test + 1,2 == 2);
//     while(a)
//     {   
//         printf("stack: %d\n",a->value);
//         a = a->next;
//     }
//     // free_matrix(test);
//     // if(!test)
//     //     printf("free success");
//     // else
//     //     printf("free fail");
    
// }