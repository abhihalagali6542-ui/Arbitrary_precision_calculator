#include "list.h"

//------------------------------------------------------------------//

void mul_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR)
{
    Dlist *res_head1=NULL;
    Dlist *res_tail1=NULL;
    Dlist *res_head2=NULL;
    Dlist *res_tail2=NULL;
    Dlist *temp2 = tail2;

    for(int count=0;temp2!=NULL;count++)
    {
        int carry=0;
        Dlist *temp1 = tail1;
        for(int i=0;i<count;i++)
        {
            insert_first(&res_head2,&res_tail2,0);
        }
        
        if(count==0)
        {
            while(temp1!=NULL)
            {
                int data = (temp1->data*temp2->data)+carry;
                temp1 = temp1->prev;
                carry=data/10;
                insert_first(&res_head1,&res_tail1,data%10);
            }
        }
        else
        {
            while(temp1!=NULL)
            {
                int data = (temp1->data*temp2->data)+carry;
                temp1 = temp1->prev;
                carry=data/10;
                insert_first(&res_head2,&res_tail2,data%10);
            }
        }

        if(carry)
        {
            if(count==0) 
                insert_first(&res_head1,&res_tail1,carry);
            else         
                insert_first(&res_head2,&res_tail2,carry);
        }

        if(res_head1!=NULL && res_head2!=NULL)
        {
            add_operation(res_head1,res_tail1,res_head2,res_tail2,headR,tailR);
            delete_list(&res_head1,&res_tail1);
            delete_list(&res_head2,&res_tail2);
            res_head1 = *headR;
            res_tail1 = *tailR;
            *headR = NULL;
            *tailR = NULL;
        }
        temp2=temp2->prev;
    }

    display_result(head1,tail1,head2,tail2,res_head1,res_tail1,'x');
}

//------------------------------------------------------------------//
