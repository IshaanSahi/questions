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
    vector<vector<string>> printTree(TreeNode* root) {
        TreeNode* temp=root;
        int ht=height(temp);
        int c = pow(2, ht) - 1;   
        vector<vector<string>>result= vector<vector<string>>(ht, vector<string>(c, ""));
        result[0][(c-1)/2]=to_string(root->val);
        create(root,0,(c-1)/2,ht,result);
        return result;
    }
    int height(TreeNode* root) {
    if(root == nullptr)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}
    void create(TreeNode* root,int r,int c,int ht,vector<vector<string>>&result){
        int col = pow(2, ht) - 1,nr,nc; 
        if(root==nullptr)
            return;
        if(root->left!=nullptr){
            nr=r+1;nc=c-pow(2,ht-r-2);
            result[nr][nc]=to_string(root->left->val);
            create(root->left,nr,nc,ht,result);
        }
        if(root->right!=nullptr){
            nr=r+1;nc=c+pow(2,ht-r-2);
            result[nr][nc]=to_string(root->right->val);
            create(root->right,nr,nc,ht,result);
        }
        return ;
    }
};