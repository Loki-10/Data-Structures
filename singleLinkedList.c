#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int choice, i, x, pos, position, flag, size=0;
struct node *head, *temp, *beforeNode, *lastNode, *newNode;

void insertAtBeginning()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data :");
    scanf("%d",&newNode->data);
    if(head==NULL)
    {
        head=lastNode=newNode;
        lastNode->next=0;
    }
    else
    {
        newNode->next=head;
        head=newNode;
    }
    size++;
}

void  insertAtPosition()
{
    printf("Enter the position of element to be inserted : ");
    scanf("%d",&pos);
    if(pos==0)
    {
        insertAtBeginning();
    }
    else
    {
        temp=head;
        for(i=0;i<pos-1;i++)
        {
                beforeNode=temp;
                temp=temp->next;
                if(temp==NULL)
                {
                    printf("\nPosition not found");
                    return;
                }
        }
                newNode = (struct node *)malloc(sizeof(struct node));
                printf("\nEnter Data :");
                scanf("%d",&newNode->data);
                beforeNode->next=newNode;
                newNode->next=temp;
     }
     size++;
}

void insertAtEnd()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data :");
    scanf("%d",&newNode->data);
    if(head==NULL)
    {
        head=lastNode=newNode;
        lastNode->next=0;
    }
    else
    {
        lastNode->next=newNode;
        lastNode=newNode;
        lastNode->next=0;
    }
    size++;
}

void deleteAtBeginning()
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp=head;
        head=head->next;
        printf("The Deleted Element is %d",temp->data);
        free(temp);
    }
    size--;
}

void deleteAtPosition()
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("Enter the position of element to be deleted: ");
        scanf("%d",&pos);
        if(pos==0)
        {
            deleteAtBeginning();
        }
        else if(pos==size)
        {
            deleteAtEnd();
        }
        else
        {
            temp=head;
            for(i=0;i<pos-1;i++)
            {
                beforeNode=temp;
                temp=temp->next;
                if(temp==NULL)
                {
                    printf("Position not found");
                    return;
                }
            }
            beforeNode->next=temp->next;
            printf("The Deleted Element is %d",temp->data);
            free(temp);
        }
    }
    size--;
}

void deleteAtEnd()
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        for(i=1,temp=head;i<=size;i++,temp=temp->next)
        {
            if(i==size-1)
            {
                temp->next=0;
                printf("The Deleted Element is %d",lastNode->data);
                free(lastNode);
                lastNode=temp;
                size--;
                return;
            }
        }
    }
}

void display()
{
     if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp=head;
        printf("\n");
        while(temp!=0)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

void search()
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("Enter Element to be searched : ");
        scanf("%d",&x);
        temp=head;
        flag=position=0;
        while(temp!=0)
        {
            position++;
            if(temp->data==x)
            {
                printf("\nThe Position of element %d is %d",x,position);
                flag=1;
                break;
            }
            temp=temp->next;
        }
        if(flag=0)
        {
            printf("Element %d not found",x);
        }
    }
}

int main()
{
    while(1)
    {
        printf("\nSingly Listed List Operations :");
        printf("\n1. Insert At Beginning \n2. Insert At Specified Position \n3. Insert At End");
        printf("\n4. Delete At Beginning \n5. Delete At Specified Position \n6. Delete At End");
        printf("\n7. Display Elements in Listed List \n8. Search Elements in Listed List \n9. Size of Linked List \n10.Exit");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insertAtBeginning();
                break;

            case 2:
                insertAtPosition();
                break;

            case 3:
                insertAtEnd();
                break;

            case 4:
                deleteAtBeginning();
                break;

            case 5:
                deleteAtPosition();
                break;

            case 6:
                deleteAtEnd();
                break;

            case 7:
                display();
                break;

            case 8:
                search();
                break;

            case 9:
                printf("\nThe size of Linked List is %d",size);
                break;

            case 10:
                exit(0);
                break;

            default:
                printf("Enter Valid Choice!");
                break;
        }
    }
    return 0;
}
