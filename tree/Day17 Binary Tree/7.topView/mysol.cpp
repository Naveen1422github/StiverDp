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
void f(TreeNode<int>* root, int hDis, map<int, pair<int,int>> &map, int level){
    if(root == NULL) return ;

    if(map.find(hDis)==map.end() || level < map[hDis].second){
        map[hDis] = make_pair(root->val, level);
    }
    f(root->left, hDis-1, map, level+1);
    f(root->right, hDis+1, map, level+1);
}


vector<int> getTopView(TreeNode<int> *root) {
   map<int, pair<int, int>> m;
   vector<int> ans;
   f(root, 0, m, 0); 

   for(const auto& i : m){
    ans.push_back(i.second.first);
   }

   return ans;
}

