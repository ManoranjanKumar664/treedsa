#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *front=0;
node *rear=0;
void insert(int);
void out();
void show();
void peekstart();
void peekend();

int main()
{
    show();
    insert(50);
    insert(60);
    insert(70);
    insert(80);
    show();
    out();
    show();
    peekstart();
    peekend();
    return 0;
}

void insert(int x)
{
    node *temp=new node;
    temp->data=x;
    temp->next=0;
    if(front==0)
    {
        front=temp;
        rear=temp;
        cout<<"element inserted at start: "<<temp->data<<endl;
    }
    else
    {
        front->next=temp;
        front=temp;
        cout<<"element inserted: "<<temp->data<<endl;
        // front=temp;
    }
}

void out()
{
    if(rear==0)
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    else
    {
        if(front==rear)
        {
            front=0;
        }
        node *temp=rear;
        rear=rear->next;
        cout<<"deleted element: "<<temp->data<<endl;
        free(temp);
    }
}

void show()
{
    if(rear==0)
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    else
    {
        cout<<"all elements are: ";
        node *temp=rear;
        while(temp!=0)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

void peekstart()
{
    if(rear==0)
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    else
    {
        cout<<"first element is: ";
        cout<<rear->data<<endl;
    }
}

void peekend()
{
    if(front==0)
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    else
    {
        cout<<"last element is: "<<front->data<<endl;
    }
}