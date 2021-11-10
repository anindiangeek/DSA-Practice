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

    // displaying till top only
    int i = 0;
    for (int i = 0; i < temp->top + 1; i++)
        printf("%d | ", temp->S[i]);
    printf("\n");
}

int main()
{
    // REVERSING AN Array using stack.
    // this can be done dynamically to show in class I have made it like this.
    
    int A[5];

    struct Stack s = init(5);

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &A[i]);
        push(&s, A[i]);
    }

    puts("Initial Array is :");
    for (int i = 0; i < 5; i++)
        printf("%d ", A[i]);

    // toreverse we just need to pop and push.
    for (int i = 0; i < 5; i++)
        A[i] = pop(&s);

    // printing reversed array;
    puts("\n\nReversed Array is :");

    for (int i = 0; i < 5; i++)
        printf("%d ", A[i]);

    return 0;
}