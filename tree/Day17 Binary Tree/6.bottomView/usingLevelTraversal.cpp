#include <bits/stdc++.h> 
using namespace std;

/*************************************************************
 
    Following is the Binary Tree node structure.

    template <typename T>
    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/


vector<int> bottomView(BinaryTreeNode<int> *root){
   map<int, int> m;
   vector<int> ans;
   if(root==NULL) return ans;
   queue<pair<BinaryTreeNode<int>* ,int>> q;

   q.push({root, 0});
   
   while (!q.empty())
   {
        auto it = q.front();

        BinaryTreeNode<int>* node = it.first;
        int hDis = it.second;
        m[hDis] = node->data;

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
