#include<iostream>
using namespace std;

class Queue
{
    int size;
    int front;
    int rear;
    int* Q;
public:
    Queue(int size);
    ~Queue();
    bool is_full();
    bool is_empty();
    void enqueue(int x);
    int dequeue();
    void display();
};
Queue::Queue(int size)
{
    this->size = size;
    front = rear = -1;
    Q = new int[size];
}
Queue::~Queue()
{
    delete[] Q;
}
bool Queue::is_full()
{
    if (rear == size - 1)
        return true;
    else
        return false;
}
bool Queue::is_empty()
{
    if (front == rear)
        return true;
    else
        return false;
}
void Queue::enqueue(int x)
{
    if (is_full())
        cout << "queue overflow" << endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}
int Queue::dequeue()
{
    int x;
    if (is_empty())
        cout << "queue underflow";
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}
void Queue::display()
{
    for (int i = front +1; i <= rear; i++)
    {
        cout << Q[i] << " - ";
    }
    cout << endl;
}
int main()
{
    int A[] = { 1,2,3,4,5 };
    int n = 10;
    Queue q(n);
    for (int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
    {
        q.enqueue(A[i]);
    }
    q.display();
    q.enqueue(10);
    q.display();
    cout<<q.dequeue()<<endl;
    q.display();
}