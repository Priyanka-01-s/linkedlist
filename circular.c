// ALL OPERATIONS ON A CIRCULAR LINKED LIST
// Create
// traverse
// Insert
// Delete
// reverse

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} * head;

void createLinkedList(int);
void insertLinkedList_beg(int data);
void insertLinkedList_mid(int data, int pos);
void insertLinkedList_end(int data);
void deleteLinkedList_beg();
void deleteLinkedList_pos(int pos);
void deleteLinkedList_end();
int search(int data);
void display();

int main()
{

    int n;
    printf("ENTER THE NUMBER OF NODES :");
    scanf("%d", &n);

    createLinkedList(n);
    display();
    int data;
    printf("Enter the data you want to insert at te beggining :");
    scanf("%d", &data);
    insertLinkedList_beg(data);
    display();
    int pos;
    printf("Enter the data you want to insert :");
    scanf("%d", &data);
    printf("\nEnter the position you want the data to be inserted in the list :");
    scanf("%d", &pos);
    insertLinkedList_mid(data, pos);
    display();
    printf("Enter the data you want to insert :");
    scanf("%d", &data);
    insertLinkedList_end(data);
    display();
    printf("First element is deleted :");
    deleteLinkedList_beg();
    display();
    printf("Enter the place you want to delete :");
    scanf("%d", &pos);
    deleteLinkedList_pos(pos);
    display();
    printf("Last element deleted :");
    deleteLinkedList_end();
    display();
    int index;
    printf("Enter the data for search :");
    scanf("%d", data);
    search(data);
    printf("%d found at %d position.\n", data, (index + 1));
    display();
    return 0;
}

void createLinkedList(int n)
{
    struct node *temp, *q;
    int data;
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter the datament of node 1 :");
    scanf("%d", &data);

    head->data = data;
    head->link = NULL;
    q = head;

    for (int i = 2; i <= n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));

        if (temp == NULL)
        {
            printf("NO SPACE");
            break;
        }

        printf("Enter the datament of node i :");
        scanf("%d", &data);

        temp->data = data;
        temp->link = NULL;

        q->link = temp;
        q = temp;
    }
    q->link = head;
}

void insertLinkedList_beg(int data)
{
    struct node *temp, *q;
    if (head == NULL)
    {
        printf("No space for memory allocation");
        exit(0);
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->link = head;
        q = head;

        while (q->link != head)
        {
            q = q->link;
        }
        q->link = temp;
        head = temp;
    }
}

void insertLinkedList_mid(int data, int pos)
{
    struct node *temp, *q;
    if (head == NULL)
    {
        printf("THE LIST IS EMPTY");
        return;
    }
    else if (pos == 1)
    {
        insertLinkedList_beg(data);
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        q = head;
        for (int i = 2; i < pos; i++)
        {
            q = q->link;
        }
        temp->link = q->link;
        q->link = temp;
    }
}

void insertLinkedList_end(int data)
{
    struct node *temp, *q;
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        q = head;
        while (q->link != head)
        {
            q = q->link;
        }
        q->link = temp;
        temp->link = head;
    }
}

void deleteLinkedList_beg()
{

    struct node *q;
    if (head == NULL)
    {
        printf("Nothing to delete.");
        return;
    }
    else
    {
        q = head;
        while (q->link != head)
        {
            q = q->link;
        }
        q->link = head->link;
        free(head);
        head = q->link;
    }
}

void deleteLinkedList_pos(int pos)
{
    struct node *temp, *q;
    if (head == NULL)
    {
        printf("No space for deletion.");
        return;
    }
    temp = head;
    for (int i = 1; i < pos; i++)
    {
        q = temp;
        temp = temp->link;
    }
    q->link = temp->link;
    free(temp);
}

void deleteLinkedList_end()
{
    if (head == NULL)
    {
        printf("No space for deletion.");
        return;
    }
    else
    {
        struct node *temp, *q;
        temp = head;
        while (temp->link != head)
        {
            q = temp;
            temp = temp->link;
        }
        q->link = temp->link;
        free(temp);
    }
}

int search(int data)
{
    int index = 0;
    struct node *temp, *q;
    q = temp;
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        do
        {
            if (q->data == data)
                return data;

            q = q->link;
            index++;
        } while (q != head);
    }

    return 1;
}

void display()
{
    struct node *q;
    int n = 1;
    printf("The linked list is :\n");
    q = head;
    if (q != NULL)
    {
        do
        {
            printf("Elements are %d\n", q->data);
            q = q->link;
        } while (q != head);
    }
}