#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Không thể cấp phát bộ nhớ!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
            printf("->");
        current = current->next;
    }
    printf("->NULL\n");
}

void printDetailed(struct Node *head)
{
    struct Node *current = head;
    int index = 1;
    while (current != NULL)
    {
        printf("Node %d: %d\n", index, current->data);
        index++;
        current = current->next;
    }
}

int main()
{
    int values[5] = {1, 2, 3, 4, 5};
    struct Node *head = NULL;
    struct Node *tail = NULL;

    for (int i = 0; i < 5; i++)
    {
        struct Node *newNode = createNode(values[i]);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printList(head);
    printDetailed(head);

    return 0;
}
