#include "list.h"

//------------------------------------------------------------------//

int mul_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR,char sign)
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
            if(insert_first(&res_head2,&res_tail2,0)==FAILURE)
            {
                printf("ERROR: Unable to insert data at first\n");
                return FAILURE;
            }
        }
        
        if(count==0)
        {
            while(temp1!=NULL)
            {
                int data = (temp1->data*temp2->data)+carry;
                temp1 = temp1->prev;
                carry=data/10;
                if(insert_first(&res_head1,&res_tail1,data%10)==FAILURE)
                {
                    printf("ERROR: Unable to insert data at first\n");
                    return FAILURE;
                }
            }
        }
        else
        {
            while(temp1!=NULL)
            {
                int data = (temp1->data*temp2->data)+carry;
                temp1 = temp1->prev;
                carry=data/10;
                if(insert_first(&res_head2,&res_tail2,data%10)==FAILURE)
                {
                    printf("ERROR: Unable to insert data at first\n");
                    return FAILURE;
                }
            }
        }

        if(carry)
        {
            if(count==0) 
                if(insert_first(&res_head1,&res_tail1,carry)==FAILURE)
                {
                    printf("ERROR: Unable to insert data at first\n");
                    return FAILURE;
                }
            else         
                if(insert_first(&res_head2,&res_tail2,carry)==FAILURE)
                {
                    printf("ERROR: Unable to insert data at first\n");
                    return FAILURE;
                }
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
    
    remove_zero(&res_head1);
    if(sign == '-')
        insert_first(&res_head1,&res_tail1,'-');

    if(printDll(res_head1,res_tail1)==LIST_IS_EMPTY)
    {
        printf("INFO: List is Empty\n");
        return FAILURE;
    }
    return SUCCESS;
}

//------------------------------------------------------------------//
