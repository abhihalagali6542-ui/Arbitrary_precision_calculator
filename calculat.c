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

//------------------------------------------------------------------//

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
        if(tail1!=NULL && tail2!=NULL)
        {
            sum = tail1->data + tail2->data + carry;
            carry = sum/10;            
            insert_first(head3,tail3,sum%10);
            tail1 = tail1->prev;
            tail2 = tail2->prev;
        }
        else if(tail1!=NULL && tail2==NULL)
        {
            sum = tail1->data + carry;
            carry = sum/10;
            insert_first(head3,tail3,sum%10); 
            tail1 = tail1->prev;
        }
        else if(tail1==NULL && tail2!=NULL)
        {
            sum = tail2->data + carry;
            carry = sum/10;
            insert_first(head3,tail3,sum%10); 
            tail2 = tail2->prev;
        }
    }
    if(carry == 1)
            insert_first(head3,tail3,1);
}

//------------------------------------------------------------------//

void get_list_len(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,int *list1_count,int *list2_count)
{
    while(head1!=NULL)
    {
        (*list1_count)++;
        head1 = head1->next;
    }
    while(head2!=NULL)
    {
        (*list2_count)++;
        head2 = head2->next;
    }
    // printf("\n%d %d\n",*list1_count,*list2_count);
}

//------------------------------------------------------------------//

int compare_lists(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2)
{
    int list1_count = 0,list2_count = 0;
    get_list_len(head1,tail1,head2,tail2,&list1_count,&list2_count);

    if(list1_count > list2_count)
        return -1;
    else if(list1_count < list2_count)
        return -2;
    else if(list1_count == list2_count)
    {
        while(head1->data == head2->data)
        {
            head1 = head1->next;
            head2 = head2->next;
            
            if(head1==NULL && head2==NULL)
            return -1;
        }

        if(head1->data > head2->data)
            return -1;
        else if(head1->data < head2->data)
            return -2;
    }
}

//------------------------------------------------------------------//

void sub_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **head3,Dlist **tail3)
{
    int diff = 0,barrow=0;
    while(tail1!=NULL || tail2!=NULL)
    {
        if(tail1!=NULL && tail2!=NULL)
        {
            if(tail1->data < tail2->data)
            {
                tail1->data = tail1->data+10;
                diff = tail1->data - tail2->data - barrow;
                barrow = 1;
            }
            else
            {
                diff = tail1->data - tail2->data - barrow;
                barrow=0;
            }

            insert_first(head3,tail3,diff%10);
            tail1 = tail1->prev;
            tail2 = tail2->prev;
        }
        else if(tail1!=NULL && tail2==NULL)
        {
            diff = tail1->data - barrow;
            if(diff<0)
            {
                diff=diff+10;
                barrow = 1;
            }
            else
                barrow = 0;

            insert_first(head3,tail3,diff%10);
            tail1 = tail1->prev;
        }
        else if(tail1==NULL && tail2!=NULL)
        {
            diff = tail2->data - barrow;
            if(diff<0)
            {
                diff=diff+10;
                barrow = 1;
            }
            else
                barrow = 0;

            insert_first(head3,tail3,diff%10);
            tail2 = tail2->prev;
        }
    }
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
    int ret;
    switch(opr)
    {
        case '+':
            add_operation(head1,tail1,head2,tail2,head3,tail3);
        break;
        
        case '-':
            if((ret=compare_lists(head1,tail1,head2,tail2)) == -1)
            {
                sub_operation(head1,tail1,head2,tail2,head3,tail3);
            }
            else if(ret == -2)
            {
                sub_operation(head2,tail2,head1,tail1,head3,tail3);
                insert_first(head3,tail3,'-');
            }
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
