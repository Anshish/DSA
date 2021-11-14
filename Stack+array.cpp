#include <iostream>
using namespace std;

class Stack
{
    int size;
    int top;
    int* S;
public:
    Stack(int size);
    ~Stack();
    int is_full();
    int is_empty();
    void push(int x);
    void pop();
    void peek(int pos);
    void display();
    void stack_top();
};
Stack::Stack(int size)
{
    this->size = size;
    top = -1;
    S = new int[size];
}
Stack::~Stack()
{
    delete S;
}
int Stack::is_full()
{
    if (top == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Stack::is_empty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void Stack::push(int x)
{
    if (is_full())
    {
        cout << "stack overflow" << endl;
    }
    else
    {
        top++;
        S[top] = x;
    }
}
void Stack::pop()
{
    int x = 1;
    if (is_empty())
    {
        cout << "stack underflow";
    }
    else
    {
        x = S[top];
        top--;
    }
    cout << "poped element: " << x << endl;
}
void Stack::peek(int pos)
{
    int x = -1;
    if (top - pos + 1 < 0 || top - pos + 1 == size)
    {
        cout << "invalid position";
    }
    else
    {
        x = S[top - pos + 1];
    }
    cout << "element at pos " << pos << " is: " << x << endl;;
}
void Stack::stack_top()
{
    if (is_empty())
    {
        cout << "stack underflow";
    }
    else
    {
        cout << "element at top is: " << S[top] << endl;
    }
}
void Stack::display()
{
    for (int i = top; i >= 0; i--)
    {
        cout << S[i] << " | " << flush;
    }
    cout << endl;
}
int main()
{
    int A[] = { 1,3,5,7,9 };
    int n;
    cout << "enter size of array: "; cin >> n;
    Stack stk(n);
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        stk.push(A[i]);
    }
    stk.display();
    stk.peek(3);
    stk.stack_top();
    stk.display();
}