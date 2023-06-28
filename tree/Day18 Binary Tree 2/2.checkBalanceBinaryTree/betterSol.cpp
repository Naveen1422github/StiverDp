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
// tc = o(N) , sc = o(N) in general height of tree 
int f(BinaryTreeNode<int>* root){
    if(root==NULL) return 0;

    int lh = f(root->left);
    int rh = f(root->right);

    if(lh==-1 || rh == -1 || abs(lh-rh)>1) return -1;

    return max(lh, rh) + 1;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    
    if(f(root)==-1)return false;

    return true;
}