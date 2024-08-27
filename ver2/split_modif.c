#include "push_swap.h"

// static int ft_strlen(char *s)
// {
//     int i = 0;
//     while(s[i])
//         i++;
//     return (i);
// }

char *split_modif(char **s)
{
    char *holder;
    int strlen = 0;
    int f = 0;
    int i = 1;
    int x = 0;
    while(s[i])
    {   
        f = 0;
        while(s[i][f])
            f++;
        strlen += f;  
        i++;
    }
    strlen += i;
    holder = malloc(sizeof(char) * (strlen + 1));
    if(!holder)
        return (NULL);
    i = 1;
    x = 0;
    while(s[i])
    {
        f = 0;
        while(s[i][f])
        {
            holder[x + f] = s[i][f];
            f++;
        }
        x += f;
        holder[x++] = ' ';
        i++;
    }
    holder[x - 1] = '\0';
    
    return (holder);
}

// int main()
// {   
//     char *s = "Hello there world Hi threeeee wwgwgwgw 12114124";
//     char **res = ft_split(s,' ');
//     char *t = split_modif(res);
//     printf("%s\n",s);

//     int i = 0;
//     while(i <= 7)
//     {
//         free(res[i]);
//         i++;
//     }
//     free(res);
//     free(t);

// }
