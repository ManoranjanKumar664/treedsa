#include<iostream>
using namespace std;
int a[5];
int front=-1;
int rear=-1;
int n=5;

void insert(int);
void out();
void show();

int main()
{
    show();
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    insert(70);
    show();
    out();
    out();
    // out();
    // out();
    show();
    insert(500);
    show();
    return 0;
}

void insert(int x)
{
    if((rear==0)&&(front==(n-1)))
    {
        cout<<"full"<<endl;
        return;
    }
    else if(rear==(front+1))
    {
        cout<<"full"<<endl;
        return;
    }
    else
    {
        front=(front+1)%n;
        a[front]=x;
        cout<<"inserted at index: "<<front<<endl;
        if(rear==-1)
        {
            rear=0;
        }
    }
}

void out()
{
    if((front==-1)&&(rear==-1))
    {
        cout<<"emtpy"<<endl;
        return;
    }
    else
    {
        cout<<"element deleted from index:"<<rear<<"="<<a[rear]<<endl;
        // a[rear]=0;
        if(rear==front)
        {
            rear=-1;
            front=-1;
            return;
        }
        rear=(rear+1)%n;
 
    }
}

void show()
{
    if((rear==-1)&&(front==-1))
    {
        cout<<"queue empty"<<endl;
        return;
    }
    else
    {
        cout<<"all elements are:"<<endl;
        int i=rear;
        while(i!=front)
        {
            cout<<a[i]<<" ";
            i=(i+1)%n;
        }
        cout<<a[i];
        cout<<endl;
    }
}