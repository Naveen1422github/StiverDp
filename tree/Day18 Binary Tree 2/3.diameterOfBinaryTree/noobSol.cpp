/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
// tc = o(n*n)

int h(TreeNode<int>* root){
    if(root==NULL) return 0;

    int lh = h(root->left);
    int rh = h(root->right);

    return max(lh, rh) + 1;
}

int f(TreeNode<int> *root, int maxi){
    if(root==NULL) return 0;
    
    maxi = max(maxi, h(root->left) + h(root->right));

    maxi = max(maxi, max( f(root->left, maxi), f(root->right, maxi) ) );

    return maxi;

}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	return f(root, 0);
}
