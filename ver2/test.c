#include <stdlib.h>
#include <stdio.h> 
typedef struct s_list
{
    int val;
    struct s_list *prev;
    struct s_list *next;
}   t_list;

t_list *new_node(int val)
{
    t_list *new_node = malloc(sizeof(t_list));
    if(!new_node)
        return (NULL);
    new_node->val = val;
    new_node->prev = NULL;
    new_node->next = NULL;
    return (new_node);
}
void lst_addfront(t_list **lst,t_list *new)
{
    if(!lst || !new)
        return ;
    new->next = *lst;
    *lst = new;
}
t_list *lst_last(t_list *lst)
{   
    if(!lst)
        return (NULL);
    while(lst->next)
        lst = lst->next;
    return (lst);
}
static void rotate(t_list **stack)
{
    if(!stack || !*stack)
        return ;
    t_list *last_node = lst_last(*stack);
    last_node->next = *stack;
    *stack = (*stack)->next; 
    (*stack)->prev = NULL;
    last_node->next->prev = last_node;
    last_node->next->next = NULL;
}

static void reverse_rotate(t_list **stack)
{
    if(!stack || !*stack)
        return ;
    t_list *last_node = lst_last(*stack);
    last_node->prev->next = NULL;
    last_node->next = *stack;
    *stack = last_node;
    last_node->next->prev = last_node;
    last_node->prev = NULL;
}

static void swap(t_list **stack)
{
    if(!*stack || !stack)
        return ;
    *stack = (*stack)->next;
    (*stack)->prev->prev = *stack;
    (*stack)->prev->next = (*stack)->next;
    if((*stack)->next)
        (*stack)->prev->next = (*stack)->prev;
    (*stack)->next = (*stack)->prev;
    (*stack)->prev = NULL;    
}

static void push_cmd(t_list **a, t_list **b)
{
    t_list *to_push;

    if(!*a)
        return ;
    to_push = *a;
    *a = (*a)->next;
    if(*a)
        (*a)->prev = NULL;
    to_push->prev = NULL;
    if(!*b)
    {   
        *b = to_push;
        to_push->next = NULL;
    }
    else
    {
        to_push->next = *b;
        to_push->next->prev = to_push;
        *b = to_push;
    }
}
int main()
{
    t_list *node1;
    node1 = malloc(sizeof(t_list));
    node1->next = malloc(sizeof(t_list));
    node1->next->next = malloc(sizeof(t_list));
    node1->next->next->next = malloc(sizeof(t_list));
    node1->val = 42;
    node1->next->val = 4322;
    node1->next->next->val = 65453;
    node1->next->next->next->val = 3131313;
    node1->prev = NULL;
    node1->next->prev = node1;
    node1->next->next->prev = node1->next;
    node1->next->next->next->prev = node1->next->next;
    node1->next->next->next->next = NULL;

    t_list *node2;
    node2 = NULL;
    
    swap(&node1);
    // reverse_rotate(&node1);
    // push_cmd(&node1,&node2);
    // push_cmd(&node1,&node2);
    // push_cmd(&node1,&node2);
    // push_cmd(&node1,&node2);
    while(node1)
    {
        printf("Node 1: %d\n",node1->val);
        node1 = node1->next;
    }
    while(node2)
    {
        printf("Node 2: %d\n",node2->val);
        node2 = node2->next;
    }
}