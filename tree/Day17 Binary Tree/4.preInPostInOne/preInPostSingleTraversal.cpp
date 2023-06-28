#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

// tc(3n) oc(3n)
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){

    vector<vector<int>> ans;
    stack<pair<BinaryTreeNode<int>*, int>> st;
    if(root == NULL) return ans;

    st.push({root,1});

    vector<int> in;
    vector<int> pre;
    vector<int> post;
    
    while(!st.empty()){

        auto it = st.top();
        st.pop();

        //this is pre
        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left != NULL){
              st.push({it.first->left, 1});
            }
        }

        // this is for in
        else if(it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right != NULL){
              st.push({it.first->right, 1});
            }
        }

        // this is for post
        else {
            post.push_back(it.first->data);
        }
    }

    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
            
    return ans;
}