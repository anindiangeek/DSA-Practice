#include <bits/stdc++.h>
using namespace std;
class Node
{
  public:
    int data;
    Node *next;
};
Node *head = nullptr;
Node *last = nullptr;

/*
// there is a faster way in an single iterartion to find the middle Node
// by using concept of fast and slow pointers.
// fast moves twice and slow moves once
// the distance coved by slow will half the distance covered by fast
// that is half

     Node *MiddleNode(){
    Node *slow=head;
    Node *fast=head;
    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
     }

*/
void Create(int a[], int n)
{
    Node *temp1 = new Node;
    temp1->data = a[0];
    temp1->next = nullptr;
    head = temp1;
    last = temp1;

    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node;
        temp->data = a[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
}
void Display()
{
    // iterative approach
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void Display(Node *p)
{
    // recursive approach
    if (p)
    {
        cout << p->data << " ";
        Display(p->next);
    }
    else
        cout << "\n";
}
void RDisplay(Node *p)
{
    if (p)
    {
        RDisplay(p->next);
        cout << p->data << " ";
    }
}
void InsertAtHead(int x)
{
    if (head == nullptr)
    {
        Node *temp = new Node;
        temp->data = x;
        temp->next = nullptr;
        head = temp;
        last = temp;
    }
    else
    {
        Node *temp = new Node;
        temp->data = x;
        temp->next = head;
        head = temp;
    }
}

void InsertAtTail(int x)
{
    // without using tail pointer.
    if (!head)
        InsertAtHead(x);
    else
    {
        Node *itr = head;
        while (itr->next != nullptr)
            itr = itr->next;
        Node *temp = new Node;
        temp->data = x;
        temp->next = nullptr;
        itr->next = temp;
        last = temp;
    }
}

int Length()
{
    int count = 0;
    Node *itr = head;
    while (itr)
    {
        count++;
        itr = itr->next;
    }
    return count;
}

void Insert(int data, int pos = -1)
{
    if (head)
    {
        switch (pos)
        {
        case -1:
            InsertAtTail(data);
            break;
        case 0:
            InsertAtHead(data);
            break;
        default:
            if (pos > 0 && pos < Length())
            {
                Node *itr = head;
                for (int i = 0; i < pos - 1; i++)
                    itr = itr->next;
                Node *temp = new Node;
                temp->data = data;
                temp->next = nullptr;
                if (!itr->next)
                {
                    itr->next = temp;
                    last = temp;
                }
                else
                {
                    temp->next = itr->next;
                    itr->next = temp;
                }
            }
            else
                cerr << "Out of bound";
            break;
        }
    }
    else
        InsertAtHead(data);
}

int DeleteAtHead()
{
    int data;
    if (head)
    {
        Node *temp = head;
        head = temp->next;
        data = temp->data;
        delete temp;
        return data;
    }
    else
        cerr << "No Nodes to delete";
}

int DeleteAtTail()
{
    if (head)
    {
        if (head == last)
            return DeleteAtHead();
        else
        {
            int data;
            Node *itr = head;
            while (itr->next != last)
                itr = itr->next;
            Node *temp = last;
            data = temp->data;
            delete temp;
            itr->next = nullptr;
            last = itr;
            return data;
        }
    }
    else
        cerr << "No Nodes to delete" << endl;
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
        if (pos > 0 && pos <= Length())
        {
            Node *itr = head;
            for (int i = 0; i < pos - 2; i++)
                itr = itr->next;
            Node *temp = itr->next;
            if (!temp->next)
                return DeleteAtTail();
            else
            {
                itr->next = temp->next;
                delete temp;
            }
            break;
        }
        else
            cerr << "Out of Bound" << endl;
    }
}

// recursive solution for reversing the linklist;
void reverse(Node *p)
{
    if (p->next == nullptr)
    {
        head = p;
        return;
    }
    reverse(p->next);
    Node *q = p->next;
    q->next = p;
    p->next = nullptr;
}

Node *ITRreverse(Node *p)
{
    // iterartive reverse.
    Node *prev, *curr, *agla;
    prev = nullptr;
    curr = head;
    agla = nullptr;
    while (curr != nullptr)
    {
        agla = curr->next;
        curr->next = prev;
        prev = curr;
        curr = agla;
    }
    head = prev; // I made it to current
    return head;
}
int main()
{
    int a[] = {8, 4, 5, 3, 6, 9, 10, 34};
    int n = sizeof(a) / sizeof(int);
    Create(a, n);
    Node *newhead = nullptr;
    newhead = ITRreverse(head);
    cout << Length() << endl;
    Display(newhead);
    return 0;
}