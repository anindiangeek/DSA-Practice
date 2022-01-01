#include <stdio.h>
#include <stdlib.h>
#define size 10

int front = -1, rear = -1, dequeue[size];

void insert(int val)
{
    if (rear == size - 1)
    {
        printf("\nQueue Overflow\n");
        return;
    }

    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
        rear = rear + 1;

    dequeue[rear] = val;
}
int delete_front()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue Underflow\n");
        return 0;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front = front + 1;
}

int delete_rear()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue Underflow \n");
        return 0;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        rear = rear - 1;
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\nEmpty Queue, Nothing to print yet\n");
        return;
    }

    else
    {
        printf("\nDisplaying the elements   ");
        while (i <= rear)
        {
            printf(" -> %d", dequeue[i]);
            i = (i + 1) % size;
        }
    }
}

int main()
{
    int a = 0, b;
    while (a != 4)
    {
        puts("\nWhich Operation you want to perform?");
        puts("1)Enqueue");
        puts("2) Dequeue / Delete");
        puts("3) Display / Transverse");
        puts("4) Exit");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter the value to insert in the queue : ");
            scanf("%d", &b);
            insert(b);
            break;
        case 2: {
            printf("\n1) From Front\n2) From Rear\nWhich operation do you want to perform : ");
            scanf("%d", &b);
            switch (b)
            {
            case 1:
                delete_front();
                break;
            case 2:
                delete_rear();
                break;
            default:
                break;
            }
            break;
        }
        case 3:
            display();
            break;
        case 4:
            exit;
        default:
            break;
        }
        display();
    }
    return 0;
}