/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// case 2 where null node are counted problem at leetcode
#include<bits/stdc++.h>
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int maxi = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root,1});

        if(root==NULL) return ans;
        int min = 1;

        while(!q.empty()){

            int size = q.size();
            vector<int> ind ;

            min = q.front().second;

            for(int i=0; i<size; i++){
                auto pair = q.front();
                q.pop();
                TreeNode* temp = pair.first;
                int in = pair.second - min;
            
                ind.push_back(in);

                if(temp->left) q.push({temp->left, 2*in});
                if(temp->right) q.push({temp->right, 2*in+1});
                
            }
            
            ans = ind.back() - ind.front()  + 1;
            maxi = max(ans, maxi);
        }
        return maxi;
    }
};

