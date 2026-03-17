#include<iostream>
using namespace std;
struct node 
{
    int data;
    node *left;
    node *right;
};
node* create();
void show(node*);
void inorder(node*);
void postorder(node*);
node *root=0;

int main()
{
    root=create();
    show(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    return 0;
}

node* create()
{
    int x=0;
    cout<<"enter -1 for no new node"<<endl;
    cin>>x;
    if(x==-1)
    {
        cout<<"no elemenet entered"<<endl;
        return 0;
    }    
    else
    {
        node *temp=new node;
        cout<<"enter data"<<endl;
        cin>>temp->data;
        // cout<<"enter left child of "<<temp->data<<endl;
        temp->left=create();
        // cout<<"enter right child of "<<temp->data<<endl;
        temp->right=create();
        return temp;
    }
}

void show(node *x)
{
    if(x==0)
    {
        // cout<<"tree not created"<<endl;
        return;
    }
    else
    {
        cout<<x->data;
        show(x->left);
        show(x->right);
    }
}

void inorder(node *x)
{
    if(x==0)
     return;
    else
     {
        inorder(x->left);
        cout<<x->data;
        inorder(x->right);
     }
}

void postorder(node *x)
{
    if(x==0)
     return;
    else
    {
        postorder(x->left);
        postorder(x->right);
        cout<<x->data;
    }
}

