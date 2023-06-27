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
void postorder(TreeNode *boot, vector<int> &a){

    if(boot==NULL)
    return ;

    postorder(boot->left, a);
    postorder(boot->right, a);
    a.push_back(boot->data);
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> a;
    postorder(root, a);
    return a;
}