#include<iostream>
using namespace std;

struct node
{
int data;
node *left;
node *right;
};

node *root=0;
void insert(node*&, int);
node* createnode(int);
void inorder(node*);

int main()
{
 insert(root, 40);
 insert(root, 50);
 insert(root, 60);
//  cout<<root->right->right->data<<endl;
 inorder(root);
 return 0;
}

node* createnode(int x)
{ 
 node *temp=new node;
 temp->data=x;
 temp->left=0;
 temp->right=0;
 return temp;
}

void insert(node *&q, int x)
{
//  node *n=q;
 if(q==0)
 {
     q=createnode(x);
     return;
 }
 node *prev=0;
 node *n=q;
 while(n!=0)
 {
prev=n;
if( x==n->data)
 {
cout<<"cannot insert, elemene already available"<<endl;
return;
}
else if(x<n->data)
 n=n->left;
else
 n=n->right;
}

node *temp=createnode(x);
if(x<prev->data)
 prev->left=temp;
else
 prev->right=temp;

}

void inorder(node *n)
{
    if(n==0)
     {
        // cout<<"element not available"<<endl;
        return;
     }
     else
     {
         inorder(n->left);
         cout<<n->data<<" ";
         inorder(n->right);
     }
}
