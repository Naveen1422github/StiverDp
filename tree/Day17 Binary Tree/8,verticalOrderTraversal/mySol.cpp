#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

void f(TreeNode<int>* root, int hDis, int vDis, map<int, map<int, vector<int>>>& m) {
    if (root == NULL) return;

    m[hDis][vDis].push_back(root->data);

    f(root->left, hDis - 1, vDis + 1, m);
    f(root->right, hDis + 1, vDis + 1, m);
}

vector<int> verticalOrderTraversal(TreeNode<int>* root) {
    vector<int> ans;
    map<int, map<int, vector<int>>> m;

    f(root, 0, 0, m);

    for (auto& it1 : m) {
        for (auto& it2 : it1.second) {
            for (int i = 0; i < it2.second.size(); i++) {
                ans.push_back(it2.second[i]);
            }
        }
    }

    return ans;
}

