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

// tc = o(n) sc = o(n)
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> a;
    if(root == NULL) return a;
    
    stack<TreeNode*> s;
    s.push(root);

    while(!s.empty()){
        TreeNode *node = s.top();
        s.pop();

        if(node->right!=NULL) s.push(node->right);
        if(node->left!=NULL) s.push(node->left);

        a.push_back(node->data);
    }

    return a;
}