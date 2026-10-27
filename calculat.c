#include "list.h"

//------------------------------------------------------------------//

int create_node(Dlist **head,Dlist **tail,char *str)
{
    for(int i=0;str[i]!=0;i++)
    {
        int data =  str[i]-48;
        insert_last(head,tail,data);
    }

    return SUCCESS;
}

//------------------------------------------------------------------//

int insert_last(Dlist **head,Dlist **tail,int data)
{
    if(*head == NULL && *tail == NULL)
        {
            Dlist *newnode = malloc(sizeof(Dlist));
            if(newnode == NULL)
                return FAILURE;

            newnode->data = data;
            newnode->next = NULL;
            newnode->prev = NULL;
            *head = newnode;
            *tail = newnode;
            return SUCCESS;
        }

    Dlist *newnode = malloc(sizeof(Dlist));
        if(newnode == NULL)
           return FAILURE;

        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = *tail;
        (*tail)->next = newnode;
        *tail = newnode;

    return SUCCESS;
}

int insert_first(Dlist **head,Dlist **tail,int data)
{
    if(*head == NULL && *tail == NULL)
        {
            Dlist *newnode = malloc(sizeof(Dlist));
            if(newnode == NULL)
                return FAILURE;

            newnode->data = data;
            newnode->next = NULL;
            newnode->prev = NULL;
            *head = newnode;
            *tail = newnode;
            return SUCCESS;
        }

    Dlist *newnode = malloc(sizeof(Dlist));
        if(newnode == NULL)
           return FAILURE;

        newnode->data = data;
        newnode->prev = NULL;
        newnode->next = *head;
        (*head)->prev = newnode;
        *head = newnode;

    return SUCCESS;
}

//------------------------------------------------------------------//

void add_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **head3,Dlist **tail3)
{
    int sum=0,carry=0;
    while(tail1!=NULL || tail2!=NULL)
    {
        sum = carry;
        
        if(tail1!=NULL)
        {
            sum = sum+tail1->data;
            tail1 = tail1->prev;
        }
        if(tail2!=NULL)
        {
            sum = sum+tail2->data;
            tail2 = tail2->prev;
        }

        carry = sum/10;
        // printf("%d ",sum%10);
        insert_first(head3,tail3,sum%10);
    }
}

//------------------------------------------------------------------//

void sub_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **head3,Dlist **tail3)
{

}

//------------------------------------------------------------------//

void mul_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **head3,Dlist **tail3)
{
    
}

//------------------------------------------------------------------//

void div_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **head3,Dlist **tail3)
{
    
}

//------------------------------------------------------------------//

void calculator(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **head3,Dlist **tail3,char opr)
{
    switch(opr)
    {
        case '+':
        printf("Addition : ");
            add_operation(head1,tail1,head2,tail2,head3,tail3);
        break;
        
        case '-':
            sub_operation(head1,tail1,head2,tail2,head3,tail3);
        break;
        
        case '*':
            mul_operation(head1,tail1,head2,tail2,head3,tail3);
        break;
        
        case '/':
            div_operation(head1,tail1,head2,tail2,head3,tail3);
        break;

        default:
        printf("Invalid opertor\n");
    }
}

//------------------------------------------------------------------//
