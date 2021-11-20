#include<iostream>
using namespace std;

class Node
{
public:
    Node* lchild;
    int data;
    Node* rchild;
};
class BST
{
    Node* root;
public:
    BST();
    Node* get_root();
    void insert(int key);
    void inorder(Node* p);
    Node* search(int key);
    int height(Node* p);
    Node* in_prec(Node* p);
    Node* in_suc(Node* p);
    Node* delete_node(Node* p, int key);
};
BST::BST()
{
    root = NULL;
}
Node* BST::get_root()
{
    return root;
}
void BST::insert(int key)
{
    Node* p = root;
    Node* t;
    Node* r = NULL;
    if (root == NULL)
    {
        t = new Node;
        t->data = key;
        t->lchild = NULL;
        t->rchild = NULL;
        root = t;
        return;
    }
    while (p != NULL)
    {
        r = p;
        if (key < p->data)
        {
            p = p->lchild;
        }
        else if (key > p->data)
        {
            p = p->rchild;
        }
        else
        {
            return;
        }
    }
    t = new Node;
    t->data = key;
    t->lchild = NULL;
    t->rchild = NULL;
    if (key < r->data)
    {
        r->lchild = t;
    }
    else
    {
        r->rchild = t;
    }
}
void BST::inorder(Node* p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << ", ";
        inorder(p->rchild);
    }
}
Node* BST::search(int key)
{
    Node* p = root;
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        else if (key < p->data)
        {
            p = p->lchild;
        }
        else {
            p = p->rchild;
        }
    }
    return NULL;
}
int BST::height(Node* p)
{
    int l = 0;
    int r = 0;
    if (p != NULL)
    {
        l = height(p->lchild);
        r = height(p->rchild);
        if (l > r)
            return l + 1;
        else
            return r + 1;
    }
    return 0;
}
Node* BST::in_prec(Node* p)
{
    while (p != NULL && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}
Node* BST::in_suc(Node* p)
{
    while (p != NULL && p->lchild != NULL)
    {
        p->lchild;
    }
    return p;
}
Node* BST::delete_node(Node* p, int key)
{
    Node* q;
    if (p == NULL)
    {
        return NULL;
    }
    if (p->lchild == NULL & p->rchild == NULL)
    {
        if (p == root)
        {
            root = NULL;
        }
        delete p;
        return NULL;
    }
    if (key < p->data)
    {
        p->lchild = delete_node(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = delete_node(p->rchild, key);
    }
    else
    {
        if (height(p->lchild) > height(p->rchild))
        {
            q = in_prec(p->lchild);
            p->data = q->data;
            p->lchild = delete_node(p->lchild, q->data);
        }
        else
        {
            q = in_suc(p->rchild);
            p->data = q->data;
            p->rchild = delete_node(p->rchild, q->data);
        }
    }
    return p;
}
int main()
{
    BST bst;
    //order of insertion decides how bst will be formed
    bst.insert(45);
    bst.insert(25);
    bst.insert(20);
    bst.insert(30);
    bst.insert(43);
    bst.insert(40);
    bst.insert(35);
    bst.insert(42);
    bst.insert(10);
    bst.inorder(bst.get_root());
    Node* temp;
    temp = bst.in_prec(bst.get_root());
    cout << "in_prec: " << temp->data << endl;
    temp = bst.in_suc(bst.get_root());
    cout << "in_suc: " << temp->data << endl;
    bst.inorder(bst.get_root());
    cout << endl;
    bst.delete_node(bst.get_root(), 45);
    bst.inorder(bst.get_root());

} 