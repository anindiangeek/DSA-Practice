#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int frontindex;
    int rearindex;
    int *Arr;
};

void create(struct queue *q)
{
    printf("\nEnter the size of the queue : ");
    scanf("%d", &q->size);
    q->frontindex = q->rearindex = -1;
    q->Arr = (int *)malloc(sizeof(int) * q->size);
}

int isfull(struct queue *q)
{
    return (q->rearindex == q->size - 1) ? 1 : 0;
}

int isEmpty(struct queue *q)
{
    return (q->frontindex == q->rearindex) ? 1 : 0;
}

void enqueue(struct queue *q, int data)
{
    if (isfull(q))
        printf("\nQueue is full\n");
    else
        q->Arr[++q->rearindex] = data;
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
        return -1;
    else
        return q->Arr[q->frontindex++];
}

void display(struct queue *q)
{
    puts("\nQUEUE :\n");
    for (int i = q->frontindex + 1; i <= q->rearindex; i++)
        printf("%d => ", q->Arr[i]);
    printf("\n");
    printf("\n");
}

int main()
{
    struct queue q;
    create(&q);
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
            display(&q);
            break;
        case 1:
            printf("\nEnter the data to Enqueue :");
            scanf("%d", &data);
            enqueue(&q, data);
            break;
        case 2:
            printf("\nRemoving %d from the queue", dequeue(&q));
            break;
        default:
            break;
        }
    }
}