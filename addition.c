#include "list.h"

//------------------------------------------------------------------//

void add_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR)
{
    int sum=0,carry=0;
    while(tail1!=NULL || tail2!=NULL)
    {
        if(tail1!=NULL && tail2!=NULL)
        {
            sum = tail1->data + tail2->data + carry;
            carry = sum/10;            
            insert_first(headR,tailR,sum%10);
            tail1 = tail1->prev;
            tail2 = tail2->prev;
        }
        else if(tail1!=NULL && tail2==NULL)
        {
            sum = tail1->data + carry;
            carry = sum/10;
            insert_first(headR,tailR,sum%10); 
            tail1 = tail1->prev;
        }
        else if(tail1==NULL && tail2!=NULL)
        {
            sum = tail2->data + carry;
            carry = sum/10;
            insert_first(headR,tailR,sum%10); 
            tail2 = tail2->prev;
        }
    }
    if(carry)
        insert_first(headR,tailR,carry);
}

//------------------------------------------------------------------//
