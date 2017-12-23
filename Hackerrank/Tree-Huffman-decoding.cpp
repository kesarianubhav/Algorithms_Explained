/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/

int p=0;
void decoder(node *root , string s , int i)
{
    if( root->data!='\0' ) { cout<<root->data; p=i; }
    else
    {
        if(s[i]=='0')  decoder(root->left,s,i+1);
        if(s[i]=='1')  decoder(root->right,s,i+1);
    }
}

void decode_huff(node * root,string s)
{
    for(int i=0;i<s.length();)
    {
        p=0;
        decoder(root,s,i);
        i=p;
    }
}
