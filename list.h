#ifndef LIST_H
#define LIST_H

#define SUCCESS 0
#define FAILURE -1
#define NORMAL -2
#define SWAP -3

#include<stdlib.h>
#include<stdio.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}Dlist;

//------------------------------------------------------------------//

void remove_zero(Dlist **head);
void printDll(Dlist *head,Dlist *tail);
int delete_list(Dlist **head, Dlist **tail);
int insert_last(Dlist **head,Dlist **tail,int data);
int insert_first(Dlist **head,Dlist **tail,int data);
int create_node(Dlist **head,Dlist **tail, char *str);
int compare_lists(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2);
void calculator(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,char opr);
void add_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR);
void sub_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR);
void mul_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR);
void div_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR);
void get_list_len(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,int *list1_count,int *list2_count);
void display_result(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist *headR,Dlist *tailR,char opr);

//------------------------------------------------------------------//

#endif
