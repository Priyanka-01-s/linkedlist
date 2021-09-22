//CREATE A SINGLY LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} * head;

void createLinkedList(int n)
{
    struct node *temp, *q;
    int data;
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("NO SPACE RO ALLOCAtE MEMORY");
        exit(0);
    }
    printf("Enter te data of the node 1 :");
    scanf("%d", &data);
    head->data = data;
    head->link = NULL;

    q = head;
    for (int i = 2; i <= n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        if (temp == NULL)
        {
            printf("No SPACE TO ALLOCATE MEMORY");
            break;
        }
        printf("Enter the data of node %d :", i);
        scanf("%d", &data);

        temp->data = data;
        temp->link = NULL;

        q->link = temp;
        q = q->link;
    }
}

void displayLinkedList()
{
    struct node *q;
    q = head;
    printf("The data in the liked list are \n");
    while (q != NULL)
    {
        printf("Elements are : %d\n", q->data);
        q = q->link;
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes :");
    scanf("%d", &n);
    createLinkedList(n);
    displayLinkedList(n);
    return 0;
}