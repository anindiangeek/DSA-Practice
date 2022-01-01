#include <stdio.h>
#include <stdlib.h>
#define size 10

int front = -1, rear = -1, dequeue[size];

void insert_rear(int val)
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

void insert_front(int val)
{
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
    {
        printf("\nQueue Overflow\n");
        return;
    }
    else if (front == -1 && rear == -1)
        front = rear = 0;
    else
        front = front - 1;
    dequeue[front] = val;
}

void _delete()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue Underflow\n");
        return;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front = front + 1;
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
            printf(" -> %d", dequeue[i++]);
    }
}

int main()
{
    int a = 0, b, c;
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
        case 1: {
            printf("Enter the value to insert in the queue : ");
            scanf("%d", &c);
            puts("1)From Front");
            puts("2)From Rear");
            printf("Where? : ");
            scanf("%d", &b);
            switch (b)
            {
            case 1:
                insert_front(c);
                break;
            case 2:
                insert_rear(c);
                break;
            default:
                break;
            }
            break;
        }
        case 2:
            _delete();
            break;
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