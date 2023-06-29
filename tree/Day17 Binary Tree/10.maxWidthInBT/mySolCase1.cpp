#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
// case 1 = where null nodes are excluded
int getMaxWidth(TreeNode<int> *root)
{
    int maxi = 0;

    queue<TreeNode<int>*> q;
    q.push(root);

    if(root==NULL) return maxi;

    while(!q.empty()  ){
        vector<int> ans;
        int size = q.size();

        for(int i=0; i<size; i++){
            TreeNode<int>* temp = q.front();
            q.pop();
            
            ans.push_back(temp->val);
    
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        int s = ans.size();
        maxi = max(s, maxi);
    }
    
    return maxi;
}