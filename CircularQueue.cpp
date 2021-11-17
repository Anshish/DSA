#include<iostream>
using namespace std;

class CircularQueue
{
    int size;
    int front;
    int rear;
    int *Q;
public:
    CircularQueue(int size);
    ~CircularQueue();
    bool is_full();
    bool is_empty();
    void enqueue(int x);
    int dequeue();
    void display();
};
CircularQueue::CircularQueue(int size)
{
    this->size=size;
    front=rear=0;
    Q=new int[size];
}
CircularQueue::~CircularQueue()
{
    delete [] Q;
}
bool CircularQueue::is_full()
{
    if((rear+1)%size==front)
        return true;
    else
        return false;
}
bool CircularQueue::is_empty()
{
    if(front==rear)
        return true;
    else
        return false;
}
void CircularQueue::enqueue(int x)
{
    if(is_full())
        cout<<"queue overflow"<<endl;
    else
        rear=(rear+1)%size;
        Q[rear]=x;
}
int CircularQueue::dequeue()
{
    int x;
    if(is_empty())
        cout<<"queue underflow"<<endl;
    else
        front=(front+1)%size;
        x=Q[front];
}
void CircularQueue::display()
{
    int i=front+1;
    while(i!=(rear+1)%size)
    {
        cout<<Q[i]<<" - ";
        i=(i+1)%size;
    }
    cout<<endl;
}
int main()
{
    int A[]={1,2,3,4,5};
    int n=10;
    CircularQueue cq(n);
    for(int i=0;i<sizeof(A)/sizeof(A[0]);i++)
    {
        cq.enqueue(A[i]);
    }
    cq.display();
    cq.enqueue(10);
    cq.display();
    cout<<cq.dequeue();
    cq.display();
}