#include "list.h"

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

    if(create_node(&head1,&tail1,argv[1])==FAILURE)
        return FAILURE;
    if(create_node(&head2,&tail2,argv[3])==FAILURE)
        return FAILURE;
    calculator(head1,tail1,head2,tail2,argv[2][0]);
}

//------------------------------------------------------------------//
