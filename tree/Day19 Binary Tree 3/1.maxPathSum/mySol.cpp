#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

long long h(TreeNode<int>* root, long long int &maxi, int &leaf){
    if(root==NULL) return 0;

    if(!root->left && !root->right){
      leaf++;
    }

    long long int lh = h(root->left, maxi, leaf);

    long long int rh = h(root->right, maxi, leaf);
   
    maxi = max(maxi, lh+rh+root->val);

    return max(lh, rh) + root->val;
}


long long int findMaxSumPath(TreeNode<int> *root)
{
    long long int maxi=0;

    int leaf = 0;


    h(root, maxi, leaf);

    if(leaf<2) return -1;
    
    return maxi;
}