#include <iostream>
using namespace std;

class Node 
{
    public:
        Node *prev;
        int data;
        Node *next;
};
class DoublyLinkedList
{
    Node *head;
    public:
        DoublyLinkedList();
        DoublyLinkedList(int A[],int n);
        ~DoublyLinkedList();
        void display();
        void insert(int pos,int x);
        void delete_node(int pos);
        void reverse();
};
DoublyLinkedList::DoublyLinkedList()
{
    head=new Node;
    head->prev=NULL;
    head->data=0;
    head->next=NULL;
}
DoublyLinkedList::DoublyLinkedList(int A[],int n)
{
    Node *temp,*last;
    head=new Node;
    head->data=A[0];
    head->prev=head->next=NULL;
    last=head;
    for(int i=1;i<n;i++)
    {
        temp=new Node;
        temp->data=A[i];
        temp->next=last->next;
        temp->prev=last;
        last->next=temp;
        last=temp;
    }
}
DoublyLinkedList::~DoublyLinkedList()
{
    Node *p=head;
    while(head!=NULL)
    {
        head=head->next;
        delete p;
        p=head;
    }
}
void DoublyLinkedList::display()
{
    Node *p=head;
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void DoublyLinkedList::insert(int pos,int x)
{
    Node *t,*p;
    p=head;
    t=new Node;
    t->data=x;
    if(pos==0)
    {
        t->prev=NULL;
        t->next=head;
        head->prev=t;
        head=t;
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        t->prev=p;
        if(p->next!=NULL)
            p->next->prev=t;
        p->next=t;
    }
}
void DoublyLinkedList::delete_node(int pos)
{
    Node *p=head;
    if(pos==1)
    {
        head=head->next;
        if(head!=NULL)
        {
            head->prev=NULL;
        }
        delete p;
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next!=NULL)
        {
            p->next->prev=p->prev;
        }
        delete p;
    }
}
void DoublyLinkedList::reverse()
{
    Node *p=head;
    Node *t;
    while(p!=NULL)
    {
        t=p->next;
        p->next=p->prev;
        p->prev=t;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
            head=p;
    }
}
int main()
{
    int A[]={1,2,3,4,5};
    DoublyLinkedList dl(A,5);
    dl.display();
    dl.reverse();
    dl.display();
}