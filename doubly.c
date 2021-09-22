#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
    struct node *prev;
} * head, *last;

void create(int data);
void display();
void reverse();

int main()
{
    head = NULL;
    last = NULL;
    int data;
    printf("Enter the number of elemets on the doubly linkdlist :");
    scanf("%d", &data);
    create(data);
    printf("The list is :");
    display();
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
            head->link = NULL;

            last = head;

            /*
             * Create rest of the n-1 nodes
             */
            for (i = 2; i <= n; i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));

                if (newNode != NULL)
                {
                    printf("Enter data of %d node: ", i);
                    scanf("%d", &data);

                    newNode->data = data;
                    newNode->prev = last; // Link new node with the previous node
                    newNode->link = NULL;

                    last->link = newNode; // Link previous node with the new node
                    last = newNode;       // Make new node as last/previous node
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

void display()
{
    struct node *temp;
    int n = 1;

    head = temp;
    while (temp != NULL)
    {
        printf("The %d data in the list : %d", n, temp->data);
        n++;
        temp = temp->link;
    }
}

void reverse()
{
    struct node *temp;
    int n = 0;

    if (last == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = last;
        printf("\n\nDATA IN THE LIST:\n");

        while (temp != NULL)
        {
            printf("DATA of last-%d node = %d\n", n, temp->data);

            n++;

            /* Move the current pointer to previous node */
            temp = temp->prev;
        }
    }
}