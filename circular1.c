//CREATING A CIRCULAR LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} * head;

void createCircularLinkedList(int);
void display();

int main()
{
    int n;
    printf("ENTER THE NUMBER OF NODES\n");
    scanf("%d", &n);
    createCircularLinkedList(n);
    display();

    return 0;
}

void createCircularLinkedList(int n)
{
    struct node *temp, *q;
    int data;
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("NO SPACE TO ALLOCATE A MEMORY");
        exit(0);
    }
    printf("Enter the data of node 1 :");
    scanf("%d", &data);

    head->data = data;
    head->link = NULL;

    q = head;
    for (int i = 2; i <= n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        if (temp == NULL)
        {
            printf("NO SPACE TO ALLOCATE A MEMORY");
            break;
        }
        printf("Enter the data of node i :");
        scanf("%d", &data);

        temp->data = data;
        temp->link = NULL;

        q->link = temp;
        q = temp;
    }
    q->link = head;
}

void display()
{
    struct node *q;
    int n = 1;
    q = head;
    if (q != NULL)
    {
        do
        {
            printf("ELEMENTS ARE : %d", q->data);
            q = q->link;
            n++;
        } while (q != head);
    }
}