#include <stdio.h>
#include <stdlib.h>

// implimentation of stack using dynamic array in C;

struct Stack
{
    int *S;
    int size;
    int top;
};

// function to check wether the stack is full;

int isFull(struct Stack *temp)
{
    // bool is not identified in C ;_;, also cannot return using short notation
    if (temp->top == temp->size - 1)
        return 1;
    else
        return 0;
}

// function to check weather the stack is Empty

int isEmpty(struct Stack *temp)
{
    if (temp->top == -1)
        return -1;
    else
        return 0;
}

// this function creates an Stack of size and returns it;
struct Stack create()
{
    // creating a temprary stack
    struct Stack s;

    // defining the top pointer as -1;
    s.top = -1;
    printf("Enter the size of Stack :");
    scanf("%d", &s.size);
    s.S = (int *)malloc(sizeof(int) * s.size);
    return s;
}

// issue with this function-->solved
struct Stack init(int size)
{
    printf("\n%d \n", size);
    struct Stack s;
    // this was the issue didn't add size to the struct and display function was using it.
    s.size = size;
    s.top = -1;
    s.S = (int *)malloc(sizeof(int) * size);
    return s;
}

void push(struct Stack *temp, int data)
{
    if (!isFull(temp))
        temp->S[++temp->top] = data;
    else
        printf("\nStack Overflow\n");
}

int pop(struct Stack *temp)
{
    int data = -1;
    if (!isEmpty(temp))
        data = temp->S[temp->top--];
    return data;
}

void display(struct Stack *temp)
{
    // int i = 0;
    // for (int i = 0; i < temp->size; i++)
    //     printf("%d | ", temp->S[i]);
    // printf("\n");

    // displaying till top only, there is no need to display garbage values.
    int i = 0;
    for (int i = 0; i < temp->top + 1; i++)
        printf("%d | ", temp->S[i]);
    printf("\n");
}

int Largest(struct Stack *temp)
{
    int max = INT_MIN;
    for (int i = 0; i < temp->top + 1; i++)
    {
        if (temp->S[i] > max)
            max = temp->S[i];
    }
    return max;
}

int Smallest(struct Stack *temp)
{
    int min = INT_MAX;
    for (int i = 0; i < temp->top + 1; i++)
    {
        if (temp->S[i] < min)
            min = temp->S[i];
    }
    return min;
}

int main()
{
    printf("\nEnter the size of Stack : ");
    int sp = 0, T = 1, data;
    scanf("%d", &sp);
    struct Stack s = init(sp);
    while (T != -1)
    {
        puts("what you want to do ?");
        puts("0-Display");
        puts("1-Push");
        puts("2-Pop");
        puts("3-Largest Element");
        puts("4-Minimum Element");
        scanf("%d", &T);
        switch (T)
        {
        case 0:
            display(&s);
            break;
        case 1:
            printf("\n Enter data to push :");
            scanf("%d", &data);
            push(&s, data);
            break;
        case 2:
            printf("\nRemoving/Poping out the data from Top : %d has been removed\n", pop(&s));
            break;
        case 3:
            printf("\nLargest Element in Stack : %d \n", Largest(&s));
            break;
        case 4:
            printf("\nSmallest Element in Stack : %d \n ", Largest(&s));
            break;
        default:
            break;
        }
    }
    display(&s);
    return 0;
}