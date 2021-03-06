#include<iostream>
using namespace std;
#include "BinaryTreeNode.h"

BinaryTreeNode<int> *takeInput()
{

    int data;
    cin >> data;
    if(data == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);

    root -> left = takeInput();
    root -> right = takeInput();

    return root;

}
// 1 2 3 -1 4 5 -1 -1 -1 -1 6 -1 -1
void printNodes(BinaryTreeNode<int> *root){

  if(root == NULL) {
        return;
    }
    cout << root -> data << " : ";
    if(root -> left != NULL) {
        cout << root -> left -> data ;
    }
    cout  << ",  ";

    if(root -> right != NULL) {
      cout << root -> right -> data;
    }
    cout << endl;

    printNodes(root -> left);
    printNodes(root -> right);
}
 bool findANode(BinaryTreeNode<int> *root,int x){


    if(root==NULL)
        return false;

     if(root->data==x)
        return true;

    bool leftans=findANode(root->left,x);
    bool rightans=findANode(root->right,x);

     if(leftans || rightans)
        return true;

     return false;
 }
int main()
{
    cout<<"Enter the root:";
    BinaryTreeNode<int> *root=takeInput();
    printNodes(root);
    bool b=findANode(root,41);
    cout<<endl;
    cout<<b;
}

