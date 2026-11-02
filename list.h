#ifndef LIST_H
#define LIST_H

#define SUCCESS 0
#define FAILURE -1
#define NORMAL -2
#define SWAP -3
#define LIST_IS_EMPTY -4

#include<stdlib.h>
#include<stdio.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}Dlist;

//------------------------------------------------------------------//

int validation(char *,char *);
int remove_zero(Dlist **head);
int printDll(Dlist *head,Dlist *tail);
int delete_list(Dlist **head, Dlist **tail);
int insert_last(Dlist **head,Dlist **tail,int data);
int insert_first(Dlist **head,Dlist **tail,int data);
int create_node(Dlist **head,Dlist **tail, char *str);
int compare_lists(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2);
void calculator(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char opr);
char operation_type(Dlist **head1, Dlist **head2, char opr, char *sign);
int add_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR);
int sub_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR);
int mul_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR,char sign);
int div_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR);
void get_list_len(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,int *list1_count,int *list2_count);

//------------------------------------------------------------------//

#endif
