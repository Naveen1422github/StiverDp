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
//tc o(n) sc o(n)
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> a;
    stack<TreeNode*> s;
    
    while(true){
        if(root!=NULL){
            s.push(root);
            root = root->left;
        }
        else{
            if(s.empty()) break;
            root = s.top();
            s.pop();
            a.push_back(root->data);
            root = root->right;
        }
    }

    return a;
}