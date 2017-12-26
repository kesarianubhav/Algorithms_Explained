#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef struct node
{
    int data;
    struct node * left;
    struct node * right ;
}node ;


node * insert( node * root , int data )
{
    if( root==NULL) 
        {
            root = (struct node *) malloc ( sizeof(struct node ));
            root->data = data;
            root->left=NULL ;
            root->right=NULL;
        }
    else
    {
        if(root->data<data) root->right = insert(root->right,data);
        else root->left = insert(root->left,data);
    }
 return root;   
}

void printer(struct node * root )
{
    if(root!=NULL)
    {
        printer(root->left);
        cout<<root->data<<"\n";
        printer(root->right);
    }
    
}

int height(node * root)
{
    if(root==NULL) return 0;
    int h1=height(root->left);
    int h2=height(root->right);
    if(h1>h2) return h1+1;
    else return h2+1;
}

int main()
{
    int n ;
    cin >> n ;
    struct node* root = NULL ;
    int a;
    cin >> a;
    root=insert(root,a);
    for( int i=1;i<n;i++) 
    {
        cin >> a ;
        insert(root,a);
    }
    
    cout<<height(root)<<"\n";
}
