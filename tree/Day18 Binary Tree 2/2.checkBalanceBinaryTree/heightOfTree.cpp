#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int f(BinaryTreeNode<int>* root){
    if(root==NULL) return 0;

    return max(f(root->left), f(root->right)) + 1;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    
    cout<<f(root);
    return true;
}