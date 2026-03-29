#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *root=0;
void push(int);
void pop();
void show();

int main()
{
    int x;
    // cout<<"enter element"<<endl;
    // cin>>x;
    show();
    push(5);
    push(10);
    push(20);
    push(30);
    show();
    pop();
    show();
    return 0;
}

void push(int x)
{
    node *temp=new node;
    temp->data=x;
    temp->next=0;
    if(root==0)
    {
        root=temp;
        cout<<"element inserted at root."<<endl;
    }
    else
    {
        temp->next=root;
        root=temp;
        cout<<"element inserted"<<endl;
    }
}

void pop()
{
    if(root==0)
    {
        cout<<"stack is empty"<<endl;
        return;
    }
    else
    {
        node *temp=root;
        root=root->next;
        cout<<"element deleted:"<<temp->data<<endl;
        free(temp);
    }
}

void show()
{
    if(root==0)
    {
        cout<<"stack is empty"<<endl;
        return;
    }
    else
    {

        cout<<"all elements are:";
        node *temp=root;
        while(temp!=0)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;

    }
}