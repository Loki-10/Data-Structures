#include <stdio.h>
int queue[100],choice,n,front=-1,rear=-1,element,i;

void push()
{
    if(rear==n-1)
    {
        printf("\nQueue is over flow");
    }
    else
    {
        if (front ==-1)
        {
            front=0;
        }
        printf("\nEnter a value to be pushed:");
        scanf("%d",&element);
        rear++;
        queue[rear]=element;
    } 
}

void pop()
{
    if(front==-1 || front>rear)
    {
        printf("\nQueue is under flow");
    }
    else
    {
        printf("\nThe popped element is %d",queue[front]);
        front++;
    }
}

void display()
{
    if(front!=-1)
    {
        printf("\nThe elements in Queue");
        for(i=front; i<=rear; i++)
            printf("\n%d",queue[i]);
        printf("\nPress Next Choice");
    }
    else
    {
        printf("\nThe Queue is empty");
    }
}

int main()
{
    printf("Enter the size of QUEUE:");
    scanf("%d",&n);
    printf("\n Queue Operations :\n 1. Push \n 2. Pop \n 3. Display \n 4. Exit \n");
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
