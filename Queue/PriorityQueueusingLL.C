#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    Node *next;
};
void InsertAtTail(int data);
struct Node *NodeMaker(int data);

struct Node *head = nullptr;
struct Node *tail = nullptr;

int DeleteAtTail();

// to avoid code repetition made a new function named node maker
inline struct Node *NodeMaker(int data)
{
    // allocating heap memory for a node with data filled and returning a pointer
    // to it.
    struct Node *temp = (Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = nullptr;
    return temp;
}
void InsertAtHead(int data)
{
    // getting new Node.
    struct Node *NewNode = NodeMaker(data);

    // checking if it's the first push i.e list is empty
    if (!head)
        head = tail = NewNode;
    // first push, making head point to new node;

    // if already a head node exists.
    else
    {
        // New Node will point at head and we will modify the head.
        NewNode->next = head;
        head = NewNode;
    }
}
void InsertAtTail(int data)
{
    if (!head)
        InsertAtHead(data);
    else
    {

        Node *itr = head;

        while (itr->next)
            itr = itr->next;
        Node *NewNode = NodeMaker(data);
        itr->next = NewNode;
        tail = NewNode;
    }
}

int DeleteAtHead()
{
    int data = -1;
    if (head)
    {
        Node *temp = head;
        head = temp->next;
        data = temp->data;
        delete temp; // we can also use free();
        return data;
    }
    else
    {
        printf("\nNo Nodes to delete\n");
        return data;
    }
}

int DeleteAtTail()
{
    if (head)
    {
        if (head == tail)
            return DeleteAtHead();
        else
        {
            int data;
            Node *itr = head;
            while (itr->next != tail)
                itr = itr->next;
            Node *temp = tail;
            data = temp->data;
            delete temp;
            itr->next = nullptr;
            tail = itr;
            return data;
        }
    }
    else
    {
        printf("\nNo Nodes to Delete\n");
        return -1;
    }
}

void SortedInsert(int data)
{
    // if it's first push
    if (!head)
    {
        struct Node *NewNode = NodeMaker(data);
        head = tail = NewNode;
    }
    else
    {
        struct Node *itr = head, *prev = nullptr;
        while (itr->data < data && itr->next)
        {
            prev = itr;
            itr = itr->next;
        }
        if (!itr->next)
            InsertAtTail(data);
        else // insert at itr
        {
            struct Node *NewNode = NodeMaker(data);
            NewNode->next = itr;
            if (itr != head)
                prev->next = NewNode;
            else
                head = NewNode;
        }
    }
}

void createPQ()
{
    int data = 0;
    int t = 1;
    puts("Enter the data fowllowed by 1 to insert more, 0 to stop");
    while (t)
    {
        scanf("%d", &data);
        scanf("%d", &t);
        SortedInsert(data);
    }
}

int DeletePQ()
{
    return DeleteAtTail();
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    createPQ();
    int T = 0, data, pos;
    puts("Initial List is:");
    display(head);
    while (T != -1)
    {
        puts("what you want to do?");
        puts("1- Insert");
        puts("2- Delete");
        scanf("%d", &T);
        switch (T)
        {
        case 1:
            puts("Enter data to insert");
            scanf("%d", &data);
            SortedInsert(data);
            break;
        case 2:
            DeletePQ();
            display(head);
            break;
        case 3:
            display(head);
            break;
        default:
            break;
        }
    }
    return 0;
}