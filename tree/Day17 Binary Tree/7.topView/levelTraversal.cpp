#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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


vector<int> getTopView(TreeNode<int> *root) {
   map<int, int> m;
   vector<int> ans;

   if(root==NULL) return ans;
   queue<pair<TreeNode<int>* ,int>> q;

   q.push({root, 0});
   
   while (!q.empty())
   {
        auto it = q.front();

        TreeNode<int>* node = it.first;
        int hDis = it.second;

        if(m.find(hDis)==m.end())
        m[hDis] = node->val;

        q.pop();

        if(node->left != NULL){
            q.push({node->left, hDis-1});
        }

        if(node->right != NULL){
            q.push({node->right, hDis+1});
        }
   }
   

   for (const auto& i : m) {
        ans.push_back(i.second);
   }

   return ans;
}

