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
//tc o(n) sc o(n+n)
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> a;
    stack<TreeNode*> s1;
    
    while(!s1.empty() || root !=NULL){
        if(root != NULL){
            s1.push(root);
            root = root->left;
        }
        else{
            TreeNode *temp = s1.top()->right;

            if(temp == NULL){
                temp = s1.top();
                s1.pop();
                a.push_back(temp->data);

                while(!s1.empty() && temp == s1.top()->right){
                    temp = s1.top();
                    s1.pop();
                    a.push_back(temp->data);

                }

            }
            else
            root = temp;
        }
    }

    return a;
}