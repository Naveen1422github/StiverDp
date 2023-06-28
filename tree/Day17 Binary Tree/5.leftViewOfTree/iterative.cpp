#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    if(root==NULL) return ans;
    
    queue<TreeNode<int>*> q;
    
    q.push(root);

    while(!q.empty()){
        
        int size = q.size();
        queue<int>s;

        for(int i=0; i<size; i++){
            TreeNode<int> *node = q.front();
            q.pop();
            
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);

            s.push(node->data);
        }
        ans.push_back(s.front());
    }

    return ans;
}