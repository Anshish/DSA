#include <iostream>
using namespace std;

class Node  //this is used to build a structure of node
{
public:
    int data;
    Node* next;
};
class LinkedList  //this is used to build linked list
{
   public:
      Node* first;

      LinkedList()  //initialize first to NULL
      {
         first = NULL;
      }
      LinkedList(int A[], int n);
      ~LinkedList();
      void Display();
      void Count();
      void Sum();
      void Max();
      void Linear_search(int x);
      void Insert(int x,int pos);
      void insert_in_sorted(int x);
      void Delete(int pos);
      int Is_sorted();
      void Remove_duplicate();
      void Reverse();
      void Merge(LinkedList l1,LinkedList l2);
      void set(LinkedList l);
      int Is_loop();
      void Make_loop();
};
LinkedList::LinkedList(int A[], int n)
{
    Node* temp, * last;  //temp is used to make node and last is used to point to last node
    first = new Node;
    first->data = A[0];  //initialize first node of linkedlist
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}
LinkedList::~LinkedList()
{
   Node *p=first;
   while(first)
   {
      first=first->next;
      delete p;
      p=first;
   }
}
void LinkedList::Display()  //display linkedlist
{
    Node* p = first;
    while (p!=NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void LinkedList::Count()  //count number of nodes of linkedlist
{
   Node* p=first;
   int count=0;
   while(p!=NULL)
   {
      count++;
      p=p->next;
   }
   cout<<"count is: "<<count<<endl;
}
void LinkedList::Sum()
{
   Node *p=first;
   int sum=0;
   while(p!=NULL)
   {
      sum+=p->data;
      p=p->next;
   }
   cout<<"sum is: "<<sum<<endl;
}
void LinkedList::Max()  //finds max from number of elements
{
   Node *p=first;
   int m=-32768;
   while(p!=NULL)
   {
      if(p->data>m)
         m=p->data;
      p=p->next;
   }
   cout<<"maximun is: "<<m<<endl;
}
void LinkedList::Linear_search(int x)
{
   Node* p=first;
   while(p!=NULL)
   {
      if(p->data==x)
      {
         cout<<"item found"<<endl;
      }
      p=p->next;
   }
}
void LinkedList::Insert(int x,int pos)  //insert after a given node
{
   Node *t,*p;
   t=new Node;
   t->data=x;
   if(pos==0)
   {
      t->next=first;
      first=t;
   }
   else if(pos>0)
   {
      p=first;
      for(int i=0;i<pos-1;i++)
      {
         p=p->next;
      }
      t->next=p->next;
      p->next=t;
   }
}
void LinkedList::insert_in_sorted(int x)  //insert in a sorted linked list
{
   Node *p=first;
   Node *q=NULL;
   Node * t=new Node;
   t->data=x;
   while(p && p->data<x)
   {
      q=p;
      p=p->next;
   }
   if(p==first)
   {
      t->next=first;
      first=t;
   }
   else
   {
      t->next=q->next;
      q->next=t;
   }
}
void LinkedList::Delete(int pos)  //delete node after given position
{
   Node *p,*q;
   int x;
   if(pos==1)  //if first node is to be deleted
   {
      p=first;
      x=first->data;
      first=first->next;
      delete p;
   }
   else  //if it is not the first node
   {
      p=first;
      q=NULL;
      for(int i=0;i<pos-1;i++)
      {
         q=p;
         p=p->next;
      }
      q->next=p->next;
      x=p->data;
      delete p;
   }
   
}
int LinkedList::Is_sorted()  //checks if given list is sorted
{
   Node *p=first;
   int count=0;
   while(p!=NULL)
   {
      if((p->data)>(p->next->data))
      {
         return false;
      }
      p=p->next;
   }
   return true;
}
void LinkedList::Remove_duplicate()  //remove duplicates from given list
{
   Node *p=first;
   while(p!=NULL)
   {
      Node *q=p;
      Node *r=p->next;
      while(r!=NULL)
      {
         if((r->data)!=(p->data))
         {
            q=r;
            r=r->next;
         }
         else
         {
            q->next=r->next;
            delete r;
            r=q->next;
         }
      }
      p=p->next;
   }
}
void LinkedList::Reverse()
{
   Node *p=first;
   Node *q=NULL;
   Node *r=NULL;
   while(p!=NULL)
   {
      r=q;
      q=p;
      p=p->next;
      q->next=r;
   }
   first=q;
}
int LinkedList::Is_loop()  //checks if there is a loop in list
{
   Node *p,*q;
   p=q=first;
   do
   {
      p=p->next;
      q=q->next;
      if(q!=NULL)
      {
         q=q->next;
      }
   } while (p && q && p!=q);
   if(p==q)
      return 1;
   else
      return 0;
}
void LinkedList::Make_loop()  //makes a loop in a list
{                             //use in detecting a loop function
   Node *t1,*t2;
   t1=first->next->next;
   t2=first->next->next->next->next;
   t2->next=t1;
}
int main()
{
    int A1[] = { 10,20,30,40,50 };  //input number of elements
    LinkedList l(A1, 5);
    l.Display();
    l.Make_loop();
    cout<<l.Is_loop();
}