#include<iostream>
using namespace std;
int a[6];
int front=-1;
int rear=-1;
int n=6;

void insertrear(int);
void insertfront(int);
void deleterear();
void deletefront();
void showfront();
void showrear();

int main()
{
    insertrear(10);
    insertrear(20);
    insertrear(30);
    insertrear(40);
    insertrear(50);
    insertrear(60);
    insertrear(70);
    showrear();
    deleterear();
    deleterear();
    deleterear();
    deleterear();
    deleterear();
    showrear();
    deleterear();
    showrear();
    insertfront(100);
    insertfront(200);
    insertfront(300);
    showrear();

    return 0;
}

void insertfront(int x)
{
    if((front==-1&&rear==(n-1))||(front==rear+1))
    {
        cout<<"queue is full"<<endl;
        return;
    }
    else
    {
    /*  if(front==-1&&rear==-1)
         front=0; rear=0;*/

        if(front==-1 && rear==-1)
        {
            rear=0;
            front=0;
            a[front]=x;
            return;
        }
        front=(front-1+n)%n;
        a[front]=x;
        cout<<"element inserted"<<endl;
    }
}

void deleterear()
{
    if(front==-1&&rear==-1)
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    else
    {
        a[rear]=0;
        if(rear==front)
        {
         rear=-1;
         front=-1;
         return;
        }
        rear=(rear-1+n)%n;
    }
}

void insertrear(int x)
{
    if((front==0 && rear==n-1)||(front==rear+1))
    {
        cout<<"queue is full"<<endl;
        return;
    }
    else
    {
        rear=rear+1;
        a[rear]=x;
        if(front==-1)
         front=0;
        cout<<"element inserted"<<endl;
    }
}

void showrear()
{
    if(front==-1&&rear==-1)
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    else
    {
        int i=rear;
        cout<<"all elements are:";
        while(i!=front)
        {
            cout<<a[i]<<" ";
            i=(i-1+n)%n;
        }
        cout<<a[i];
        cout<<endl;
    }
}