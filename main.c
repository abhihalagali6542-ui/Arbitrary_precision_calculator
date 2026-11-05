#include "list.h"

//------------------------------------------------------------------//

int main(int argc,char *argv[])
{
    if(argc != 4)
    {
        printf("ERROR: Invalid input\nExpected format: ./a.out <operand1> <operator> <operand2>\nOperands must contain digits only.\nSupported operators: +, -, x, /.\n");
        return FAILURE;
    }

    if(validation(argv[1],argv[3])==FAILURE)
    {
        printf("ERROR: Invalid input\nExpected format: ./a.out <operand1> <operator> <operand2>\nOperands must contain digits only.\nSupported operators: +, -, x, /.\n");
        return FAILURE;
    }

    Dlist *head1 = NULL;
    Dlist *tail1 = NULL;
    Dlist *head2 = NULL;
    Dlist *tail2 = NULL;

    if(create_node(&head1,&tail1,argv[1])==FAILURE)
    {
        printf("ERROR: Unable to create node:\n");
        return FAILURE;
    }
    
    if(printDll(head1,tail1)==LIST_IS_EMPTY)
    {
        printf("INFO: List is Empty\n");
        return FAILURE;
    }
    printf("%c ",argv[2][0]);
    
    if(create_node(&head2,&tail2,argv[3])==FAILURE)
    {
        printf("ERROR: Unable to create node:\n");
        return FAILURE;
    }

    if(printDll(head2,tail2)==LIST_IS_EMPTY)
    {
        printf("INFO: List is Empty\n");
        return FAILURE;
    }
    printf("= ");
    
    calculator(&head1,&tail1,&head2,&tail2,argv[2][0]);
    return SUCCESS;
}

//------------------------------------------------------------------//
