#include <bits/stdc++.h>
using namespace std;

// I have made it in the format of C I would have rather used the C conpletely
// only but anyawys concept is clear.

class Queue
{
  public:
    int size;
    int frontindex;
    int rearindex;
    int *Arr;
    Queue()
    {
        cout << "Enter the size of the queue : ";
        cin >> size;
        frontindex = rearindex = -1;
        Arr = new int[size];
    }
};

void display(Queue *q)
{
    cout << endl;
    cout << ("current Queue is :");
    for (int i = q->frontindex + 1; i < q->size; i++)
        cout << " " << q->Arr[i] << " ";
    cout << endl;
}

bool isfull(Queue *q)
{
    return (q->rearindex == q->size - 1) ? true : false;
}

bool isEmpty(Queue *q)
{
    return (q->frontindex == q->rearindex) ? true : false;
}

void enqueue(Queue *q, int data)
{
    if (isfull(q))
        cerr << "Queue is full";
    else
        q->Arr[++q->rearindex] = data;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
        return -1;
    else
        return q->Arr[q->frontindex++];
}

int main()
{
    Queue op;
    return 0;
    count
}