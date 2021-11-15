#include<iostream>
using namespace std;

class Node
{
public:
    char data;
    Node* next;
};
class Stack
{
    Node* top;
public:
    Stack();
    ~Stack();
    void push(char x);
    int pop();
    int is_full();
    int is_empty();
    void peek(int pos);
    int stack_top();
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
void Stack::push(char x)
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
int Stack::pop()
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
    return x;
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
int Stack::stack_top()
{
    if (top != NULL)
    {
        return top->data;
    }
    else
    {
        return 0;
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

int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}
int is_operand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}
void convert(string infix)
{
    Stack stk;
    char* postfix = new char[infix.length() + 1];
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (is_operand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (precedence(infix[i]) > precedence(stk.stack_top()))
                stk.push(infix[i++]);
            else
                postfix[j++] = stk.pop();
        }
    }
    while (!stk.is_empty())
    {
        postfix[j++] = stk.pop();
    }
    postfix[j] = '\0';
    cout << postfix;
}
int main()
{
    string infix = "a+b*c";
    convert(infix);
}