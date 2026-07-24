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
class Solution {
public:
    pair<int,int> fn(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            if(root->val==1)return {0,0};
            else if(root->val==0)return {1,-1};
            return {root->val-1,root->val-1};
        }
        pair<int,int> v1={0,0}, v2={0,0};
        if(root->left){
            v1 = fn(root->left);
        }
        if(root->right){
            v2 = fn(root->right);
        }
        auto [m1,c1]=v1;
        auto [m2,c2]=v2;
        int cns = root->val-1+c1+c2;
        if(cns==0)return {m1+m2,0};
        else if(cns<0){
            int k = abs(cns);
            return {m1+m2+k,cns};
        }
        else return {m1+m2+cns, cns};
    }
    int distributeCoins(TreeNode* root) {
        auto [m,c]=fn(root);
        return m;
    }
};