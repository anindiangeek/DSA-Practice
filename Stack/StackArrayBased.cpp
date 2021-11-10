#include <iostream>

using namespace std;

// this is not working.
// dont know why but I got the concept how this thing works

class Stack
{
  public:
    int *A = nullptr;
    int size = 0;
    int top = -1;
    bool isfull(Stack *S)
    {
        (S->top == S->size - 1) ? true : false;
    }
    bool isEmpty(Stack *S)
    {
        (S->top == -1) ? true : false;
    }
    void Display(Stack *S)
    {
        if (isEmpty(S))
        {
            cerr << "Stack is Empty, Nothing to display";
        }
        else
        {
            for (int i = 0; i < S->size; i++)
                cout << S->A[i] << " ";
            cout << "\n";
        }
    }
    int Top(Stack *S)
    {
        if (isEmpty(S))
        {
            cerr << "Stack is Empty\n";
            return EXIT_FAILURE;
        }
        else
        {
            return S->A[S->top];
        }
    }
    int peek(Stack *S, int index)
    {
        // here we have to calculate the position, we are not displaying the stack
        // from below
        // here 1--> top and 2 --> top--;
        // so by generalizasation we got to know that pos=top-index+1;
        int position = S->top - index + 1;
        if (position < 0)
        {
            cerr << "Invalid Index\n";
            return EXIT_FAILURE;
        }
        else
        {
            return S->A[position];
        }
    }
    int pop(Stack *S)
    {
        if (isEmpty(S))
        {
            cerr << "nothing to pop\n";
            return EXIT_FAILURE;
        }
        else
        {
            /*
                as this is an array based implimentation
                removal of data is not mandatory
                will just simply shift the top number
        */
            int x = S->A[S->top];
            S->top--;
            return x;
        }
    }
    void push(Stack *S, int x)
    {
        if (S->top == S->size - 1)
        {
            cerr << "Stack is full\n";
        }
        else
        {
            S->top++;
            S->A[S->top] = x;
        }
    }
};
int main()
{
    Stack S;
    freopen("C:\\Users\\anind\\Documents\\DSA\\i.txt", "r", stdin);
    freopen("C:\\Users\\anind\\Documents\\DSA\\o.txt", "w+", stdout);
    freopen("C:\\Users\\anind\\Documents\\DSA\\err.txt", "w+", stderr);
    cout << "Enter the size of stack :";
    cin >> S.size;
    S.A = new int[S.size];
    S.push(&S, 4);
    S.Display(&S);
    return 0;
}