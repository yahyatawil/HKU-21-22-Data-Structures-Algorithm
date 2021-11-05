#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
 

    Node(int val)
    {
        data = val;
 
        left = NULL;
        right = NULL;
    }
};


int size(Node* node)
{
    if (node == NULL)
        return 0;
    else
        return(size(node->left) + 1 + size(node->right));
}

int depth(Node* root, int data)
{

    if (root == NULL || root->data == data)
       return 0;
    

    if (root->data < data)
       return 1 + depth(root->left, data) ;
 
    else if(root->data > data)
       return 1 + depth(root->right, data) ;
}

int maxDepth(Node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
     
        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}


int main()
{
    
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    cout<<root->left->left->data<<endl;
    root->left->left->left = new Node(5);

    root->left->left->left->right = new Node(10);
 
    //int s= size(root);
    int m_d = maxDepth(root);
    int d = depth(root,10);
    cout<<"depth of node:"<<m_d<<endl;
    cout<<"max depth:"<<d<<endl;
    return 0;
}