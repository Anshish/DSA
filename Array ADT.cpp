#include<iostream>
using namespace std;
class Array
{
    private:
        int *a;
        int size;
        int length;
    public:
        void create();
        void display();
        void append(int x);
        void insert(int x,int position);
        void delete_at_pos(int position);
        int linear_search(int key);
        int binary_search(int key);
        int get(int position);
        void set(int position,int x);
        int max();
        int min();
        int sum();
        void reverse();
        void insert_in_sorted(int x);
        int is_sorted();
        void rearrange();
        int length_arr(Array arr);
};
int Array::length_arr(Array arr)
{
    return length;
}
void Array::create()               //create array
{
    cout<<"enter size: ";cin>>size;
    a=new int[size];
    cout<<"enter length: ";cin>>length;
    for(int i=0;i<length;i++)
    {
        cout<<"enter value at index ["<<i<<"]: ";
        cin>>a[i];
    }
}
void Array::display()            //display array
{
    for(int i=0;i<length;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void Array::append(int x)       //append array
{
    a[length]=x;
    length++;
}
void Array::insert(int x,int position)  //insert into array
{
    for(int i=length;i>=position-1;i--)//index=position-1
    {
        a[i]=a[i-1];
    }
    a[position-1]=x;
    length++;
}
void Array::delete_at_pos(int position) //delete from array
{
    int x=a[position-1];             //index=position-1
    for(int i=0;i<length-1;i++)
    {
        a[i]=a[i+1];
    }
    length--;
}
int Array::linear_search(int key)    //linear search
{
    for(int i=0;i<length;i++)
    {
        if(key==a[i])
            return i+1;    //this will give position not index
    }
    return -1;
}
int Array::binary_search(int key)    ////this will give position not index
{
    int low,high,mid;
    low=0;
    high=length-1;
    while(low<high)
    {
        mid=(low+high)/2;
        if(key==a[mid])
        {
            return mid+1;   
        }
        else if (key<a[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return -1;
    cout<<endl;
}
int Array::get(int position)  //get value from particular position not index
{
    return a[position-1];
}
void Array::set(int position,int x)  //get value at particular position not index
{
    a[position-1]=x;
}
int Array::max()
{
    int max=a[0];
    for(int i=1;i<length;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    return max;
}
int Array::min()
{
    int min=a[0];
    for(int i=1;i<length;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
        }
    }
    return min;
}
int Array::sum()
{
    int sum=0;
    for(int i=0;i<length;i++)
    {
        sum+=a[i];
    }
    return sum;
}
void Array::reverse()    //this will reverse an array
{
    for(int i=0,j=length-1;i<j;i++,j--)
    {
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}
void Array::insert_in_sorted(int x)  //add element in sorted list determining itself
{
    int i=length-1;
    while(a[i]>x)
    {
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=x;
    length++;
}
int Array::is_sorted()  //check whether list is sorted
{
    for(int i=0;i<length-1;i++)
    {
        if(a[i]>a[i+1])
            return false;
    }
    return true;
}
void Array::rearrange()  //rearrange +ve's on one side and -ve's on another side
{
    int i=0,j=length-1;
    while(i<j)
    {
        while(a[i]<0)
        {
            i++;
        }
        while(a[j]>0)
        {
            j--;
        }
        if(i<j)
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
}

int main()
{
    Array arr1;
    arr1.create();
    arr1.display();
}