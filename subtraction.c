#include "list.h"

//------------------------------------------------------------------//

void sub_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR)
{
    int diff = 0,barrow=0;
    while(tail1!=NULL || tail2!=NULL)
    {
        if(tail1!=NULL && tail2!=NULL)
        {
            if(tail1->data < tail2->data)
            {
                diff = (tail1->data+10) - tail2->data - barrow;
                barrow = 1;
            }
            else
            {
                diff = tail1->data - tail2->data - barrow;
                barrow=0;
            }

            insert_first(headR,tailR,diff%10);
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

            insert_first(headR,tailR,diff%10);
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

            insert_first(headR,tailR,diff%10);
            tail2 = tail2->prev;
        }
    }
}

//------------------------------------------------------------------//
