/*************************************************************

    Following is the Binary Tree node structure for reference:

    class BinaryTreeNode{
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
#include<bits/stdc++.h>

void parentTrack(map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> &m, BinaryTreeNode<int>* root){

   queue<BinaryTreeNode<int>* > q;
   q.push(root);
   //m[root]=NULL;

   while(!q.empty()){
    
    int size = q.size();
    for(int i=0; i<size; i++){

        BinaryTreeNode<int>* temp = q.front();
        q.pop();

        if(temp->left){
            m[temp->left]=temp;
            q.push(temp->left);
        }
        if(temp->right){
            m[temp->right]=temp;
            q.push(temp->right);
        }
    }
   }
}

vector<BinaryTreeNode<int>*> printNodesAtDistanceK(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int K) {

    vector<BinaryTreeNode<int>*> ans;
    if(root==NULL)return ans;

    map<BinaryTreeNode<int>* , BinaryTreeNode<int>*> m;

    parentTrack(m, root);

    unordered_map<BinaryTreeNode<int>* , bool> visited;
    queue<BinaryTreeNode<int>*> q;
    q.push(target);

    int level = 0;

    visited[target] = true;

    while(!q.empty()){
        int size = q.size();

        if(level++ == K) break;
        for(int i=0; i<size; i++){
            BinaryTreeNode<int>* temp = q.front();
            q.pop();

            if(temp->left && !visited[temp->left]){
               q.push(temp->left);
               visited[temp->left] = true;
            }
            
            if(temp->right && !visited[temp->right ]){
               q.push(temp->right);
               visited[temp->right] = true;
            }

            if(m[temp] && !visited[m[temp]]){
                q.push(m[temp]);
                visited[m[temp]] = true;
            }
        }
    }

    while(!q.empty()){
        ans.push_back(q.front());
        q.pop();
    }

    return ans;
}