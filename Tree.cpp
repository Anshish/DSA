#include<iostream>
using namespace std;

class Node
{
public:
    Node* lchild;
    int data;
    Node* rchild;
};
class Queue
{
    int size;
    int front;
    int rear;
    Node** Q;
public:
    Queue(int size);
    ~Queue();
    bool is_full();
    bool is_empty();
    void enqueue(Node* x);
    Node* dequeue();
};
Queue::Queue(int size)
{
    this->size = size;
    front = rear = -1;
    Q = new Node * [size];
}
Queue::~Queue()
{
    delete[] Q;
}
bool Queue::is_full()
{
    if (rear == size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Queue::is_empty()
{
    if (front == rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Queue::enqueue(Node* x)
{
    if (is_full())
    {
        cout << "queue overflow";
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}
Node* Queue::dequeue()
{
    Node* x = NULL;
    if (is_empty())
    {
        cout << "queue underflow";
    }
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}
class Tree
{
public:
    Node* root;
    Tree();
    void create_tree();
    void preorder(Node* p);
    void inorder(Node* p);
    void postorder(Node* p);
    void levelorder(Node* p);
    int height(Node *p);
    int count(Node *p);
    int sum(Node *p);
    int deg2node(Node *p);
    int deg1node(Node *p);
    int deg1deg2node(Node *p);
    int leafnode(Node *p);
};
Tree::Tree()
{
    root = NULL;
}
void Tree::create_tree()
{
    Node* p;
    Node* t;
    int x;
    Queue q(25);
    root = new Node;
    cout << "enter root value: "; cin >> x;
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    q.enqueue(root);
    while (!q.is_empty())
    {
        p = q.dequeue();
        cout << "enter left child value of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "enter right child value of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}
void Tree::preorder(Node* p)
{
    if (p)
    {
        cout << p->data << ", ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void Tree::inorder(Node* p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << ", ";
        inorder(p->rchild);
    }
}
void Tree::postorder(Node* p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << ", ";
    }
}
void Tree::levelorder(Node* p)
{
    Queue q(100);
    cout << root->data << ", ";
    q.enqueue(root);
    while (!q.is_empty())
    {
        p = q.dequeue();
        if (p->lchild)
        {
            cout << p->lchild->data << ", ";
            q.enqueue(p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data << ", ";
            q.enqueue(p->rchild);
        }
    }
}
int Tree::height(Node *p)
{
    int l=0;
    int r=0;
    if(p!=NULL)
    {
        l=height(p->lchild);
        r=height(p->rchild);
        if(l>r)
            return l+1;
        else
            return r+1;
    }
    return 0;
}
int Tree::count(Node *p)
{
    int x;
    int y;
    if(p!=NULL)
    {
        x=count(p->lchild);
        y=count(p->rchild);
        return x+y+1;
    }
    return 0;
}
int Tree::sum(Node *p)
{
    int x;
    int y;
    if(p!=NULL)
    {
        x=sum(p->lchild);
        y=sum(p->rchild);
        return x+y+p->data;
    }
    return 0;
}
int Tree::deg2node(Node *p)
{
    int x=0;
    int y=0;
    if(p!=NULL)
    {
        x=deg2node(p->lchild);
        y=deg2node(p->rchild);
        if(p->lchild!=NULL && p->rchild!=NULL)
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
    }
    return 0;
}
int Tree::deg1node(Node *p)
{
    int x=0;
    int y=0;
    if(p!=NULL)
    {
        x=deg1node(p->lchild);
        y=deg1node(p->rchild);
        if(p->lchild == NULL ^ p->rchild == NULL)
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
    }
    return 0;
}
int Tree::deg1deg2node(Node *p)
{
    int x=0;
    int y=0;
    if(p!=NULL)
    {
        x=deg1deg2node(p->lchild);
        y=deg1deg2node(p->rchild);
        if(p->lchild!=NULL || p->rchild!=NULL)
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
    }
    return 0;
}
int Tree::leafnode(Node *p)
{
    int x=0;
    int y=0;
    if(p!=NULL)
    {
        x=leafnode(p->lchild);
        y=leafnode(p->rchild);
        if(p->lchild==NULL && p->rchild==NULL)
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
    }
    return 0;
}
int main()
{
    Tree t;
    t.create_tree();
    t.levelorder(t.root);
    cout<<"height: "<<t.height(t.root)<<endl;
    cout<<"count: "<<t.count(t.root)<<endl;
    cout<<"sum: "<<t.sum(t.root)<<endl;
    cout<<"nodes with deg 2: "<<t.deg2node(t.root)<<endl;
    cout<<"nodes with deg 1: "<<t.deg1node(t.root)<<endl;
    cout<<"nodes with deg 1 or 2: "<<t.deg1deg2node(t.root)<<endl;
    cout<<"leaf nodes: "<<t.leafnode(t.root)<<endl;
}