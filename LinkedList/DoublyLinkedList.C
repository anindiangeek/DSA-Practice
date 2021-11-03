#include <stdio.h>
#include <stdlib.h>

struct Node
{
    Node *prev;
    int data;
    Node *next;
};
struct Node *head = nullptr;
struct Node *tail = nullptr;

void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp)
    {
        printf("%d |<=>| ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// to avoid code repetition made a new function named node maker
inline struct Node *NodeMaker(int data)
{

    struct Node *temp = (Node *)malloc(sizeof(struct Node));
    temp->prev = nullptr;
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

void InsertAtHead(int data)
{
    struct Node *NewNode = NodeMaker(data);

    if (!head)
        head = tail = NewNode;
    else
    {
        NewNode->next = head;
        head->prev = NewNode;
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
        NewNode->prev = itr;
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
        temp->prev = nullptr;
        data = temp->data;
        free(temp);
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
            // we we do not take tail node.

            // int data;
            // Node *itr = head;
            // while (itr->next != tail)
            //     itr = itr->next;
            // Node *temp = tail;
            // data = temp->data;
            // delete temp;
            // itr->next = nullptr;
            // tail = itr;
            // return data;

            // another method faster using tail node
            int data = -1;
            Node *itr = tail->prev;
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

void create()
{
    int data = 0;
    int t = 1;
    puts("Enter the data fowllowed by 1 to insert more, 0 to stop");
    while (t)
    {
        scanf("%d", &data);
        scanf("%d", &t);
        if (!head)
            InsertAtHead(data);
        else
            InsertAtTail(data);
    }
}

void SwapHeadandTail()
{
    Node *p = head, *q = tail;
    if (head == nullptr or head == tail)
    {
        printf("\nNot Enough Nodes to perfrom Swapping\n");
        return;
    }
    // taking special case into consideration.
    // if only two Nodes are present head and a tail.
    else if (head->next == tail || tail->prev == head)
    {
        q->next = p;
        p->prev = q;
        q->prev = nullptr;
        p->next = nullptr;
        goto end;
    }
    q->next = p->next;
    p->prev = q->prev;

    q->next->prev = q;
    p->prev->next = p;

    q->prev = nullptr;
    p->next = nullptr;
end:
    head = q;
    tail = p;
}
int main()
{
    create();
    int T = 0, data, pos;
    puts("Initial List is:");
    display(head);
    while (T != -1)
    {
        puts("what you want to do?");
        puts("3- Insert At head");
        puts("4- Insert At End");
        puts("5- Delete At head");
        puts("6- Delete At tail");
        puts("7-Display");
        puts("8-SwapFirst&LastNode");
        scanf("%d", &T);
        switch (T)
        {
        case 3:
            printf("\nEnter Data:");
            scanf("%d", &data);
            InsertAtHead(data);
            break;
        case 4:
            printf("\nEnter Data:");
            scanf("%d", &data);
            InsertAtTail(data);
            break;
        case 5:
            DeleteAtHead();
            break;
        case 6:
            DeleteAtTail();
            break;
        case 7:
            display(head);
            break;
        case 8:
            SwapHeadandTail();
            break;
        default:
            break;
        }
    }
    return 0;
}