#include "list.h"

//------------------------------------------------------------------//

void printDll(Dlist *head, Dlist *tail)
{
    // if(head == NULL)
    // printf("List is empty\n");
    // return;

    printf("head -->");
    while(head!=NULL)
    {
        printf(" %d <-",head->data);
        head = head->next;
		if (head!=NULL)
		    printf("> ");
    }
    printf(" tail\n");
}

//------------------------------------------------------------------//

int main(int argc,char *argv[])
{
    if(argc != 4)
    {
        printf("Invalid arguments\n");
        return FAILURE;
    }
    Dlist *head1 = NULL;
    Dlist *tail1 = NULL;
    Dlist *head2 = NULL;
    Dlist *tail2 = NULL;
    Dlist *head3 = NULL;
    Dlist *tail3 = NULL;

    if(create_node(&head1,&tail1,argv[1])==FAILURE)
    {
        return FAILURE;
    }
    printDll(head1,tail1);
    if(create_node(&head2,&tail2,argv[3])==FAILURE)
    {
         return FAILURE;
    }
    printDll(head2,tail2);

    calculator(head1,tail1,head2,tail2,&head3,&tail3,argv[2][0]);
    printDll(head3,tail3);
}

//------------------------------------------------------------------//
