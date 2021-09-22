// Write a program to delete the nodes whose information part is divisible by 7 in a doubly linked list. For example,
// if input: 5->7->11->3->21->6, then output 5->11->3->6.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} * head, *last;

void create(int n);
void display();
void delete ();

int main()
{
    int n;
    printf("Enter the number of elements in the double linked list :");
    scanf("%d", &n);
    create(n);
    display();
    delete ();

    return 0;
}

void create(int n)
{
    int i, data;
    struct node *newNode;

    if (n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        if (head != NULL)
        {
            printf("Enter data of 1 node: ");
            scanf("%d", &data);

            head->data = data;
            head->prev = NULL;
            head->next = NULL;

            last = head;

            for (i = 2; i <= n; i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));

                if (newNode != NULL)
                {
                    printf("Enter data of %d node: ", i);
                    scanf("%d", &data);

                    newNode->data = data;
                    newNode->prev = last;
                    newNode->next = NULL;

                    last->next = newNode;
                    last = newNode;
                }
                else
                {
                    printf("Unable to allocate memory.");
                    break;
                }
            }

            printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
        }
        else
        {
            printf("Unable to allocate memory");
        }
    }
}

void delete ()
{
    struct node *q, *flag;

    q = head;

    if (q == NULL)
    {
        printf("The list is Empty");
    }
    else
    {
        printf("\n");
        while (q->next != NULL)
        {

            if (q->data % 7 == 0)
            {
                flag = q->next;
                q->next = flag->next;
                flag->next->prev = q;
                free(flag);
                printf("%d  ", q->data);
                q = q->next;
            }
        }
    }
}

void display()
{
    struct node *q;
    q = head;
    if (q == NULL)
    {
        printf("The list is Empty");
    }
    else
    {
        while (q != NULL)
        {
            printf("%d ", q->data);
            if (q != NULL)
            {
                printf("-->");
            }
            q = q->next;
        }
    }
}
