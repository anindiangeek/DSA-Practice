/*
    This is a C implimentation of singly linked list
    for storing only basic intergers "int" data types

    author : anindiangeek
    initiated on 26/08/2021
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    Node *next;
};
void InsertAtTail(int data);
struct Node *NodeMaker(int data);

/*
     I have used nullptr instead of NULL
    as this is the new latest standard for pointer allocation and considered
   safe
*/

// head pointer. taking as a global variable.
struct Node *head = nullptr;
// tail pointer to make things fast in O(1) time.(both methods are done)
struct Node *tail = nullptr;

int DeleteAtTail();

void sort(struct Node *head)
{
    struct Node *current = head, *index = nullptr;
    int temp;

    if (head == nullptr)
        return;
    else
    {
        while (current != NULL)
        {
            // Node index will point to node next to current
            index = current->next;

            while (index != NULL)
            {
                // If current node's data is greater than index's node data, swap the data between them
                if (current->data < index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

struct Node *search(int data)
{
    int idx = 1;
    Node *t = head;
    while (t)
    {
        if (t->data == data)
        {
            printf("\nElement found at Index %d\n", idx);
            return t;
        }
        t = t->next;
        idx++;
    }
    return t;
}

void insertgiven(int data, int nodedata)
{
    Node *p = search(data);
    if (!p)
        puts("element not found");
    else
    {
        Node *q = p->next;
        Node *NewNode = NodeMaker(nodedata);
        p->next = NewNode;
        NewNode->next = q;
    }
}

void deleteatgiven(int given)
{
    Node *p = search(given);
    if (!p)
        puts("element not found");
    else
    {
        Node *q = p->next;
        if (!q)
            DeleteAtTail();
        else
        {
            Node *t = q;
            p->next = q->next;
            delete (t);
        }
    }
}
int evenoddcounter(struct Node *head)
{
    int even = 0, odd = 0;
    struct Node *itr = head;
    while (itr)
    {
        (itr->data & 1) ? odd++ : even++;
        itr = itr->next;
    }
    printf("\nEven Elements:");
    printf("%d", even);
    printf("\nOdd Elements:");
    printf("%d\n", odd);
}
void MakeUsingArray(int a[], int n)
{
    struct Node *temp1 = NodeMaker(a[0]);
    head = temp1;
    tail = temp1;

    for (int i = 1; i < n; i++)
    {
        Node *temp = NodeMaker(a[i]);
        tail->next = temp;
        tail = temp;
    }
}

// Return the length of linked list.
int length(struct Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// recursive version to display LL.
void RecDisplay(struct Node *head)
{
    if (head == nullptr)
        return;
    printf("%d->", head->data);
    RecDisplay(head->next);
}

// Displaying it in reverse order using recurssion
void RevRecDisplay(struct Node *head)
{
    if (head == nullptr)
        return;
    RevRecDisplay(head->next);
    printf("%d->", head->data);
}

// iterative version to display LL.
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
    /*
        there are two methods to do so
        1- in O(n) time iterating till the last node and inserting
        2- in O(1) by using a tail pointer.

        I am implimenting both
    */
    if (!head)
        InsertAtHead(data);
    else
    {

        // Method 1 -- O(n)
        Node *itr = head;

        // itreating thtough the list till we reach the end.
        while (itr->next)
            itr = itr->next;
        // now itr will be pointing at last node.
        Node *NewNode = NodeMaker(data);
        itr->next = NewNode;
        tail = NewNode; // optional thing to handle tail if uisng this method.

        // _____________________________________

        /* 			----> METHOD 2 O(1) <-----
            //creation of New Node
            Node *NewNode = NodeMaker(data);
             tail = NewNode;
            // this is easy and simple.
        */

        //----------------------------------------
    }
}

// function to insert at any point.
void Insert(int data, int pos = -1)
{
    if (head)
    {
        if (pos == -1 or pos > length(head))
            InsertAtTail(data);
        else if (pos == 0)
            InsertAtHead(data);
        else
        {
            struct Node *itr = head;
            int i = 0;
            for (i = 0; i < pos - 1; i++)
                itr = itr->next;
            Node *NewNode = NodeMaker(data);
            if (!itr->next)
            {
                itr->next = NewNode;
                tail = NewNode;
            }
            else
            {
                NewNode->next = itr->next;
                itr->next = NewNode;
            }
        }
    }
    else
        InsertAtHead(data);
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

int Remove(int pos = -1)
{
    // -1 (default)--> pop back
    // 0 delete from head
    // pos any given position within bound
    switch (pos)
    {
    case -1:
        return DeleteAtTail();
        break;
    case 0:
        return DeleteAtHead();
    default:
        if (pos > 0 && pos <= length(head))
        {
            struct Node *itr = head;
            for (int i = 0; i < pos - 2; i++)
            {
                itr = itr->next;
            }
            struct Node *temp = itr->next;
            if (!temp->next)
                return DeleteAtTail();
            else
            {
                itr->next = temp->next;
                delete temp; // we can also use free();
            }
            break;
        }
        else
            printf("\nOut of bound\n");
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

// using iterative version to reverse a linked list
struct Node *reverseList(struct Node *head)
{
    Node *curr = nullptr;
    Node *prev = nullptr;
    Node *agla = nullptr;
    curr = head;
    while (curr)
    {
        agla = curr->next;
        curr->next = prev;
        prev = curr;
        curr = agla;
    }
    head = prev;
    return head;
}

// Recursive Reverse
void recursivereverse(struct Node *temp)
{
    if (!temp->next)
    {
        head = temp;
        return;
    }
    recursivereverse(temp->next);
    Node *q = temp->next;
    q->next = temp;
    temp->next = nullptr;
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
        puts("1- Insert");
        puts("2- Delete");
        puts("3- Insert At head");
        puts("4- Insert At End");
        puts("5- Delete At head");
        puts("6- Delete At tail");
        puts("8- Sort");
        puts("9- Length");
        puts("10- Even Odd Length");
        puts("11- Delete next to given");
        puts("12- Insert next to given");
        puts("13- Reverse a Linked list iterratively");
        puts("14- Reverse a Linked list Recursively");
        scanf("%d", &T);
        switch (T)
        {
        case 1:
            puts("Enter \"data,pos\"");
            scanf("%d", &data);
            scanf("%d", &pos);
            Insert(data, pos);
            break;
        case 2:
            puts("Enter \"pos\" to remove");
            scanf("%d", &pos);
            Remove(pos);
            break;
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
            sort(head);
            display(head);
            break;
        case 9:
            display(head);
            printf("\n%d\n", length(head));
            break;
        case 10:
            display(head);
            evenoddcounter(head);
            break;
        case 11:
            puts("Enter the data");
            scanf("%d", &data);
            deleteatgiven(data);
            display(head);
            break;
        case 12:
            puts("Enter the data after which you want to insert and data of new node");
            scanf("%d", &data);
            scanf("%d", &pos);
            insertgiven(data, pos);
            display(head);
            break;
        case 13:
            puts("Orignial List is :");
            display(head);
            head = reverseList(head);
            puts("Reversed List is :");
            display(head);
            break;
        case 14:
            puts("Orignial List is :");
            display(head);
            recursivereverse(head);
            puts("Reversed List is :");
            display(head);
            break;
        default:
            break;
        }
    }
    return 0;
}