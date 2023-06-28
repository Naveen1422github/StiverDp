/*****************************************************

    Following is the Binary Tree node structure:
    
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
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

void rlr(BinaryTreeNode<int>* root, vector<int> &v){
    
    if(root == NULL) return;
    v.push_back(root->data);
    rlr(root->left, v);
    rlr(root->right, v);
}

void rrl(BinaryTreeNode<int>* root, vector<int> &v){
    if(root == NULL) return;
    v.push_back(root->data);
    rrl(root->right, v);
    rrl(root->left, v);

}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    vector<int> q1;
    vector<int> q2;
    if(root==NULL) return true;
    rlr(root->left,q1);
    rrl(root->right, q2);

    if(q1.size()!=q2.size()) return false;

    for(int i=0; i<q1.size(); i++){
       if(q1[i]!=q2[i]) return false;
    }

    return true;
}