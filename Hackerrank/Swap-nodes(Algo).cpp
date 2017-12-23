#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define FI(i,a,b) for(int i=a;i<b;i++)
using namespace std;

typedef struct node 
{
    int data;
    struct node *left;
    struct node *right;
}node;

node * makeNode(int val)
{
    node * temp = (node *)malloc(sizeof(struct node));
    temp->left = temp->right = NULL;
    temp->data = val;
    return temp;
}

int getLevelUtil(struct node *node, int data, int level)
{
    if (node == NULL)
         return 0;
    if (node->data == data)
        return level;
    int downlevel = getLevelUtil(node->left, data, level+1);
    if (downlevel != 0)
        return downlevel;
    downlevel = getLevelUtil(node->right, data, level+1);
    return downlevel;
}


int getLevel(struct node *node, int data)
{
    return getLevelUtil(node,data,1);
}

void printer(node * root)
{
    if(root == NULL ) return ;
    printer(root->left);
    cout<<root->data<<" ";
    printer(root->right);
}

int main() 
{
    int n;
    cin >>n ;
    struct node treenode[n+1];
    struct node * tree[n+1];
    FI(i,1,n+1) tree[i]=&treenode[i];
    FI(i,1,n+1) tree[i]->data=i;
    FI(i,1,n+1) 
        {
            int a , b ;
            cin >> a >> b;
            if(a!=-1) tree[i]->left = tree[a] ; else tree[i]->left = NULL;
            if(b!=-1) tree[i]->right =tree[b] ; else tree[i]->right = NULL;
        }
    int q ;
    cin >> q ;
    int p = ceil(log2(n+1));
    while ( q -- )
    {
        int a ;
        cin >> a ;
        FI(i,1,n+1)
            {
                if((getLevel(tree[1],i))%a==0) 
                {
                    struct node * temp1 = tree[i]->left;
                    tree[i]->left=tree[i]->right;
                    tree[i]->right=temp1;
                }
            }
     printer(tree[1]);
     cout<<"\n";
    }
}
