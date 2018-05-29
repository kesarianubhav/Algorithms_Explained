/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//function Template for C++
/* A binary tree node has data, pointer to left child
   and a pointer to right child /
*/
struct Node
{
    int data;
    Node* left;
    Node* right;
};
/* Should convert tree to its mirror */
void mirror(Node* node)
{

    if(node==NULL) return ;
    if(node->left==NULL && node->right==NULL) return;
    struct Node * temp1=node->right , *temp2 =node->left;
    node->left=temp1;
    node->right=temp2;
    mirror(node->left);
    mirror(node->right);

}
