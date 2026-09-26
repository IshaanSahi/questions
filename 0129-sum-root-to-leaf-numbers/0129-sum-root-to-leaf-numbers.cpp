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
    int sumNumbers(TreeNode* root) {
        int sum=0;
        find(root,0,sum);
        return sum;
    }
    void find(TreeNode* root,int psum,int &sum){
        if(root==nullptr)
            return ;
        psum=psum*10+root->val;
        if(root->left==nullptr && root->right==nullptr){
            sum+=psum;
            return ;
        }
        if(root->left!=nullptr)
            find(root->left,psum,sum);
        if(root->right!=nullptr)
            find(root->right,psum,sum);
        // psum=(psum-root->val)/10;  no need to dox this 
    }
};