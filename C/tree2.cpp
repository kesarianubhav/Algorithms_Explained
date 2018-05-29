#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data ;
  struct Node * left;
  struct Node * right;
};

typedef struct Node Node;

Node *newNode(int item)
{
    Node *temp =  (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left  = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

void sibling(Node * node)
{
  if(node==NULL || (node->left==NULL && node->right==NULL)) return;
  if(node->right==NULL && node->left!=NULL)
    {
      sibling(node->left);
      cout<<node->left->data;
    }
    if(node->right!=NULL && node->left==NULL)
      {

      sibling(node->right);
      cout<<node->right->data;
    }
    if(node->left!=NULL && node->right!=NULL)
      {  sibling(node->left);
        sibling(node->right); }
}


int main()
{
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 10);

    sibling(root);

    return 0;
}
