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
void preorder(TreeNode *boot, vector<int> &a){

    if(boot==NULL)
    return ;

    a.push_back(boot->data);
    preorder(boot->left, a);
    preorder(boot->right, a);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> a;
    preorder(root, a);
    return a;
}