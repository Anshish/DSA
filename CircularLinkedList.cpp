#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};
class CircularLinkedList
{
    Node* head;
public:
    CircularLinkedList() { head = NULL; }
    CircularLinkedList(int A[], int n);
    ~CircularLinkedList();
    void display();
    void insert(int pos,int x);
    void delete_node(int pos);
};
CircularLinkedList::CircularLinkedList(int A[], int n)
{
    Node* temp, * last;
    head = new Node;
    head->data = A[0];
    head->next = head;
    last = head;
    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}
CircularLinkedList::~CircularLinkedList() {
    Node* p = head;
    while (p->next != head) {
        p = p->next;
    }

    while (p != head) {
        p->next = head->next;
        delete head;
        head = p->next;
    }

    if (p == head) {
        delete head;
        head = NULL;
    }

}
void CircularLinkedList::display()
{
    Node* p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
}
void CircularLinkedList::insert(int pos,int x)
{
    Node *t,*p;
    if(pos==0)
    {
        t=new Node;
        t->data=x;
        if(head==NULL)
        {
            head=t;
            head->next=head;
        }
        else
        {
            p=head;
            while(p->next!=head)
            {
                p=p->next;
            }
            p->next=t;
            t->next=head;
            head=t;
        }
    }
    else
    {
        t=new Node;
        t->data=x;
        p=head;
        for(int i=1;i<pos-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}
void CircularLinkedList::delete_node(int pos)
{
    int x;
    Node *p,*q;
    if(pos==1)
    {
        p=head;
        while(p->next!=head)
        {
            p=p->next;
        }
        x=head->data;
        if(p==head)
        {
            delete head;
            head=NULL;
        }
        else
        {
            p->next=head->next;
            delete head;
            head=p->next;
        }
    }
    else
    {
        p=head;
        for(int i=1;i<pos-1;i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
    }
}
int main()
{
    int A[] = { 1,2,3,4,5 };
    CircularLinkedList cl(A, sizeof(A) / sizeof(A[0]));
    cl.display();
}