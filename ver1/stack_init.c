#include "push_swap.h"

static long ft_atol(char *s)
{
    int conv;
    int res;

    res = 0;
    conv = 1;
    while(*s == ' ' ||(*s >= 9 && *s <= 13))
        s++;
    if(*s == '+' || *s == '-')
    {
        if(*s == '-')
            conv *= -1;
        s++;
    }
    while(*s >= '0' && *s <= '9')
    {
        res = res * 10 + (*s - '0');
        s++;
    }
    return (res * conv);
}

void stack_init(t_stack_node **a, char **av, bool flag_ac_2)
{
    long nbr;

    while(*av)
    {   
        if(error_syntax(*av))
            error_free(a,av,flag_ac_2);
        nbr = ft_atol(*av);
        if(nbr > INT_MAX || nbr < INT_MIN)
            error_free(a,av,flag_ac_2);
        if(!error_repetition(*a, (int)nbr))
            error_free(a,av,flag_ac_2);
        append_node(a, (int)nbr);
        av++;
    }
    if(flag_ac_2)
        free_matrix(av);
}
// int main()
// {
//     t_stack_node *a;
//     a = NULL;

//     char **test = (char **)malloc(sizeof(char *) * (4 + 1));
//     test[5] = {test[0] ="\0",test[1] ="42",test[2] = "432123", test[3] = "-42",test[4] = NULL};
//     stack_init(&a,test + 1,true);
//     int i = 1;
//     while(a)
//     {   
//         printf("stack: %d\n",a->value);
//         a = a->next;
//     }
//     while(test[i])
//         printf("list: %s\n",test[i++]);
//     free_matrix(test);
//     // if(!test)
//     //     printf("free success");
//     // else
//     //     printf("free fail");
    
// }