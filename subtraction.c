#include "list.h"

//------------------------------------------------------------------//

int sub_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR)
{
    int diff = 0,borrow=0;
    while(tail1!=NULL || tail2!=NULL)
    {
        if(tail1!=NULL && tail2!=NULL)
        {
            if(tail1->data < tail2->data)
            {
                diff = (tail1->data+10) - tail2->data - borrow;
                borrow = 1;
            }
            else
            {
                diff = tail1->data - tail2->data - borrow;
                borrow=0;
            }

            if(insert_first(headR,tailR,diff%10)==FAILURE)
            {
                printf("ERROR: Unable to insert data at first\n");
                return FAILURE;
            }
            tail1 = tail1->prev;
            tail2 = tail2->prev;
        }
        else if(tail1!=NULL && tail2==NULL)
        {
            diff = tail1->data - borrow;
            if(diff<0)
            {
                diff=diff+10;
                borrow = 1;
            }
            else
                borrow = 0;

            if(insert_first(headR,tailR,diff%10)==FAILURE)
            {
                printf("ERROR: Unable to insert data at first\n");
                return FAILURE;
            }
            tail1 = tail1->prev;
        }
        else if(tail1==NULL && tail2!=NULL)
        {
            diff = tail2->data - borrow;
            if(diff<0)
            {
                diff=diff+10;
                borrow = 1;
            }
            else
                borrow = 0;

            if(insert_first(headR,tailR,diff%10)==FAILURE)
            {
                printf("ERROR: Unable to insert data at first\n");
                return FAILURE;
            }
            tail2 = tail2->prev;
        }
    }
     return SUCCESS;
}

//------------------------------------------------------------------//
