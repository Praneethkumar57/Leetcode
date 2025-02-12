/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p != NULL && q != NULL){
        if(p->val != q->val){
            return(0);
        }
        else{
            bool val1, val2;
            val1 = isSameTree(p->left, q->left);
            val2 = isSameTree(p->right, q->right);
            if(val1 == 0 || val2 == 0){
                return 0;
            }
            else{
                return 1;
            }
        }
    }
    else if(p==NULL && q==NULL){
        return 1;
    }
    else if(p!=NULL && q==NULL){
        return 0;
    }
    else if(p==NULL && q!=NULL){
        return 0;
    }
    return 1;
}