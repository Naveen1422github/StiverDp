#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void inorder(TreeNode *boot, vector<int> &a){

    if(boot==NULL)
    return ;

    inorder(boot->left, a);
    a.push_back(boot->data);
    inorder(boot->right, a);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> a;
    inorder(root, a);
    return a;
}