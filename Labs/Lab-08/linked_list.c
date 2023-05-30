#include <stdio.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

Node* createNode(int data)
{
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data)
{
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, int data)
{
    if (head == NULL)
        insertAtBeginning(head, data);
    else 
    {
    Node* last = *head;
    while(last->next != NULL)
        last = last->next;
    last->next = createNode(data);
    }
}

void removeFromBeginning(Node** head)
{
    if (*head == NULL)
        return;
    Node* cur = *head;
    *head = (*head)->next;
    free(cur);
}

void removeFromEnd(Node** head)
{
    if (*head == NULL)
        return;
    else if ((*head)->next == NULL)
        removeFromBeginning(head);
    else
    {
        Node* cur = *head;
        while (cur->next->next)
            cur = cur->next;
        Node* last = cur->next;
        cur->next = NULL;
        free(last);
    }
}

Node* search(Node* head, int data)
{
    while (head && head->data != data)
    {
        head = head->next;
    }
    return head;
}

void display(Node* head)
{
    printf("Linked list: ");
    if(!head)
    {
        printf("IS EMPTY!")
        return;
    }
    while (head) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() 
{
    Node * head = NULL;

    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    display(head);

    reverseLinkedList(&head);
    display(head);

    removeFromBeginning(&head);
    display(head);

    removeFromEnd(&head);
    display(head);

    Node * res = search(head, 2);
    prontf("%d\n", res->data);

    freeLinkedList(head);

    return 0;
}
