#include <stdio.h>
int stack[100],choice,n,top=-1,element,i;

void push()
{
    if(top>=n-1)
    {
        printf("\nSTACK is over flow");
    }
    else
    {
        printf("\nEnter a value to be pushed:");
        scanf("%d",&element);
        top++;
        stack[top]=element;
    } 
}

void pop()
{
    if(top<=-1)
    {
        printf("\nStack is under flow");
    }
    else
    {
        printf("\nThe popped elements is %d",stack[top]);
        top--;
    }
}

void display()
{
    if(top>=0)
    {
        printf("\nThe elements in STACK");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        printf("\nPress Next Choice");
    }
    else
    {
        printf("\nThe STACK is empty");
    }
}

int main()
{
    printf("Enter the size of STACK:");
    scanf("%d",&n);
    printf("\n Stack Operations :\n 1. Push \n 2. Pop \n 3. Display \n 4. Exit \n");
    do
    {
        printf("\nEnter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
            {
                push();
                break;
            }
            
            case 2 :
            {
                pop();
                break;
            }
            
            case 3 :
            {
                display();
                break;
            }
            
            case 4 :
            {
                printf("Exit");
                break; 
            }
            
            default :
            {
                printf("Enter valid choice");
                break;
            }
        }
    }
    while(choice!=4);
    return 0;
}
