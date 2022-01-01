#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    int data;
};

struct Node *front = nullptr;
struct Node *rear = nullptr;

// to avoid code repetition made a new function named node maker
struct Node *NodeMaker(int data)
{
    // allocating heap memory for a node with data filled and returning a pointer
    // to it.
    struct Node *temp = (Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

void enqueue(int data)
{
    struct Node *NewNode = NodeMaker(data);

    if (!front)
        front = rear = NewNode;
    else
    {
        rear->next = NewNode;
        rear = NewNode;
    }
}

int dequeue()
{
    if (!front)
    {
        puts("Nothing to Dequeue");
        return -1;
    }

    struct Node *temp = front;
    front = front->next;
    int x = temp->data;
    delete temp;
    return x;
}

void display()
{
    struct Node *itr = front;

    while (itr)
    {
        printf("%d|=>|", itr->data);
        itr = itr->next;
    }

    printf("\n");
}

int main()
{
    int T = 0, data;
    while (T != -1)
    {
        puts("what you want to do?");
        puts("0-Display");
        puts("1-Enqueue");
        puts("2-Dequeue");
        scanf("%d", &T);
        switch (T)
        {
        case 0:
            display();
            break;
        case 1:
            printf("\nEnter the data to Enqueue :");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            printf("\nRemoved %d from the queue\n", dequeue());
            break;
        default:
            break;
        }
        display();
    }
}