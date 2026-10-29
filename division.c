#include "list.h"

//------------------------------------------------------------------//

void div_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR)
{
    Dlist *temp1 = head1;
    Dlist *head3 = NULL;
    Dlist *tail3 = NULL;
    Dlist *res_head=NULL;
    Dlist *res_tail=NULL;

    while(temp1!=NULL)
    {
        int ret,count=0;
        Dlist *temp2 = head2;

        insert_last(&head3,&tail3,temp1->data);
        temp1 = temp1->next;
        
        remove_zero(&head3);

        while((ret = compare_lists(head3,tail3,temp2,tail2))==NORMAL)
        {
            sub_operation(head3,tail3,temp2,tail2,&res_head,&res_tail);
            count++;
            delete_list(&head3,&tail3);

            head3 = res_head;
            tail3 = res_tail;
            res_head = NULL;
            res_tail = NULL;

            remove_zero(&head3);
        }
    
        insert_last(headR,tailR,count);
    }
}

//------------------------------------------------------------------//
