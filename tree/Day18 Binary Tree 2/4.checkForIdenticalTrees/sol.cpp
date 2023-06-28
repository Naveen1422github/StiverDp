#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
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

***********************************************************/

bool identicalTrees(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if(root1==NULL|| root2 == NULL) return false;

    bool val = root1->data == root2 -> data;

    bool lh = identicalTrees(root1->left, root2->left);
    bool rh = identicalTrees(root1->right, root2->right);

    return val && lh && rh;
}