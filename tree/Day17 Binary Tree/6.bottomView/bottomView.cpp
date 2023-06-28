#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

// My sol
void f(BinaryTreeNode<int>* root, int hDis, map<int, pair<int,int>> &map, int level){
    if(root == NULL) return ;

    if(level>=map[hDis].second || map.find(hDis)==map.end()){
        map[hDis] = make_pair(root->data, level);
    }
    f(root->left, hDis-1, map, level+1);
    f(root->right, hDis+1, map, level+1);
}

vector<int> bottomView(BinaryTreeNode<int> * root){

   map<int, pair<int, int>> m;
   vector<int> ans;
   f(root, 0, m, 0); 

   for(const auto& i : m){
    ans.push_back(i.second.first);
   }

   return ans;
}
