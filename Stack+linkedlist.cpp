#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};
class Stack
{
    Node* top;
public:
    Stack();
    ~Stack();
    void push(int x);
    void pop();
    int is_full();
    int is_empty();
    void peek(int pos);
    void stack_top();
    void display();
};
Stack::Stack()
{
    top = NULL;
}
Stack::~Stack()
{
    Node* p = top;
    while (top != NULL)
    {
        top = top->next;
        delete p;
        p = top;
    }
}
void Stack::push(int x)
{
    Node* t = new Node;
    if (t == NULL)
    {
        cout << "stack overflow" << endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
void Stack::pop()
{
    Node* p;
    int x;
    if (top == NULL)
    {
        cout << "stack underflow";
    }
    else
    {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    cout << "poped element is: " << x << endl;
}
int Stack::is_full()
{
    Node* t = new Node;
    if (t == NULL)
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
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void Stack::peek(int pos)
{
    if (is_empty())
    {
        cout << "stack underflow" << endl;
    }
    else
    {
        Node* p = top;
        for (int i = 0; p != NULL && i < pos - 1; i++)
        {
            p = p->next;
        }
        if (p != NULL)
        {
            cout << "item at position " << pos << " is: " << p->data << endl;
        }
        else
        {
            cout << "invalid poition" << endl;
        }
    }
}
void Stack::stack_top()
{
    if(top!=NULL)
    {
        cout<<"item at top is: "<<top->data<<endl;
    }
    else
    {
        cout<<"no item on the top"<<endl;
    }
}
void Stack::display()
{
    Node* p = top;
    while (p != NULL)
    {
        cout << p->data << " | ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    int A[] = { };
    Stack stk;
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        stk.push(A[i]);
    }
    stk.display();
    stk.peek(10);
    stk.stack_top();
}