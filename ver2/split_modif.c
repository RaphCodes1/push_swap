#include "push_swap.h"

static int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
        i++;
    return (i);
}

char *split_modif(char **s)
{
    char *holder;
    char *tmp;
    int strlen = 0;
    int tmplen = 0;
    int f = 0;
    int i = 1;
    while(s[i])
    {   
        f = 0;
        while(s[i][f])
            f++;
        f++;
        strlen += f;  
        i++;
    }
    holder = malloc(sizeof(char *) * (strlen + 1));
    if(!holder)
        return (NULL);
    i = 1;
    int x = 0;
    while(s[i])
    {
        f = 0;
        tmplen = ft_strlen(s[i]);
        tmp = malloc(sizeof(char *) * (tmplen + 2));
        while(s[i][f] != '\0')
        {
            tmp[f] = s[i][f];
            f++;
        }
        tmp[f++] = ' ';
        tmp[f] = '\0';
        f = 0;
        while(tmp[f])
        {
            holder[x + f] = tmp[f];
            f++;
        }
        x += f;
        free(tmp);
        i++;
    }
    holder[x] = '\0';
    return (holder);
}