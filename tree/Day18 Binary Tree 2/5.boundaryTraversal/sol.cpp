#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int> * root) {
  return !root -> left && !root -> right;
}

void left(TreeNode<int>* root, vector<int> &ans){

    root = root -> left;
    while (root) {
       if (!isLeaf(root)) ans.push_back(root -> data);
       if (root -> left) root = root -> left;
       else root = root -> right;
   }
}

void leaf(TreeNode<int>* root, vector<int>&ans){

  if (isLeaf(root)) {
    ans.push_back(root->data);
    return;
  }
    if(root->left) leaf(root->left, ans);
    if(root->right) leaf(root->right,ans);
 }


void right(TreeNode<int>* root, vector<int> &ans){
    root = root -> right;
    vector < int > tmp;
    while (root) {
        if (!isLeaf(root)) tmp.push_back(root -> data);
        if (root -> right) root = root -> right;
        else root = root -> left;
    }

   for (int i = tmp.size() - 1; i >= 0; --i) {
        ans.push_back(tmp[i]);
    }

}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;

    if(root == NULL) return ans;

    if(!isLeaf(root)) ans.push_back(root->data);

    left(root, ans);
    leaf(root, ans);
    right(root, ans);
   
    return ans;
}