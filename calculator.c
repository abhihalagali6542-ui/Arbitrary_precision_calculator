#include "list.h"

//------------------------------------------------------------------//

void calculator(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,char opr)
{
    Dlist *headR = NULL;
    Dlist *tailR = NULL;
    int ret;
    switch(opr)
    {
        case '+':
            add_operation(head1,tail1,head2,tail2,&headR,&tailR);
            display_result(head1,tail1,head2,tail2,headR,tailR,opr);
        break;
        
        case '-':
            if((ret=compare_lists(head1,tail1,head2,tail2)) == NORMAL)
            {
                sub_operation(head1,tail1,head2,tail2,&headR,&tailR);
            }
            else if(ret == SWAP)
            {
                sub_operation(head2,tail2,head1,tail1,&headR,&tailR);
                insert_first(&headR,&tailR,'-');
            }
            display_result(head1,tail1,head2,tail2,headR,tailR,opr);
        break;
        
        case 'x':
        case 'X':
            mul_operation(head1,tail1,head2,tail2,&headR,&tailR);
        break;
        
        case '/':
            div_operation(head1,tail1,head2,tail2,&headR,&tailR);
            display_result(head1,tail1,head2,tail2,headR,tailR,opr);
        break;

        default:
        printf("Invalid opertor\n");
    }
}

//------------------------------------------------------------------//

void remove_zero(Dlist **head)
{
    while((*head)!=NULL && (*head)->next!=NULL && (*head)->data ==0)
    {
        *head = (*head)->next;
        (*head)->prev=NULL;
    }
}

//------------------------------------------------------------------//

void printDll(Dlist *head, Dlist *tail)
{
    if(head->data == '-')
    {
        printf("%c",head->data);
        head = head->next;
    }

    remove_zero(&head);

    while(head!=NULL)
    {
        printf("%d",head->data);
        head = head->next;
    }
    printf(" ");
}

//------------------------------------------------------------------//

int delete_list(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
        return FAILURE;
    
    while(*head != NULL)
    {
        Dlist *temp = *head;
        (*head)->prev = NULL;
        *head = (*head)->next;
        free(temp);
    }
    *head = NULL;
    *tail = NULL;
    return SUCCESS;
}

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
        return NORMAL;
    else if(list1_count < list2_count)
        return SWAP;
    else if(list1_count == list2_count)
    {
        while(head1->data == head2->data)
        {
            head1 = head1->next;
            head2 = head2->next;
            
            if(head1==NULL && head2==NULL)
            return NORMAL;
        }

        if(head1->data > head2->data)
            return NORMAL;
        else if(head1->data < head2->data)
            return SWAP;
    }
}

//------------------------------------------------------------------//

void display_result(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist *headR,Dlist *tailR,char opr)
{
    printDll(head1,tail1);
    printf("%c ",opr);
    printDll(head2,tail2);
    printf("= ");
    printDll(headR,tailR);
    printf("\n");
}

//------------------------------------------------------------------//
