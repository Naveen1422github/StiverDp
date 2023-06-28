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
//tc o(n) sc o(n+n) generaly we don't consider size of data strucuter that we are going
// to return that why we didn't consider space of vector a 
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> a;
    if(root == NULL) return a;

    stack<TreeNode*> s1;
    stack<int>s2;
    s1.push(root);
    
    while(!s1.empty()){
        root = s1.top();
        s1.pop();
        s2.push(root->data);

        if(root->left !=NULL) s1.push(root->left);
        if(root->right !=NULL) s1.push(root->right);
    }

    while(!s2.empty()){
        a.push_back(s2.top());
        s2.pop();
    }

    return a;
}