#ifndef LIST_H
#define LIST_H

#define FAILURE -1
#define SUCCESS 0

#include<stdlib.h>
#include<stdio.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}Dlist;

//------------------------------------------------------------------//

int create_node(Dlist **head,Dlist **tail, char *str);
int insert_last(Dlist **head,Dlist **tail,int data);
void printDll(Dlist *head,Dlist *tail);
void calculator(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **head3,Dlist **tail3,char opr);
int compare_lists(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2);
void get_list_len(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,int *list1_count,int *list2_count);
void add_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **head3,Dlist **tail3);
void sub_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **head3,Dlist **tail3);
void mul_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **head3,Dlist **tail3);
void div_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **head3,Dlist **tail3);

//------------------------------------------------------------------//

#endif
