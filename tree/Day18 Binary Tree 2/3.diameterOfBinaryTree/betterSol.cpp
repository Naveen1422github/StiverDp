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
// tc = o(n) sc = o(n)

int h(TreeNode<int>* root, int &maxi){
    if(root==NULL) return 0;

    int lh = h(root->left, maxi);

    int rh = h(root->right, maxi);
   
    maxi = max(maxi, lh+rh);

    return max(lh, rh) + 1;
}


int diameterOfBinaryTree(TreeNode<int> *root)
{
    int dia=0;
	h(root, dia);

    return dia;
}
