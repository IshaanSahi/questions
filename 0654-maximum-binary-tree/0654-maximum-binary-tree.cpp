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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return find(nums,0,nums.size()-1);

    }
    TreeNode* find(vector<int>&nums,int i,int j){
        if(i>j)
            return nullptr;
        int maxi=nums[i],idx=i,k=i;
        for(k=i;k<=j;k++){
            if(nums[k]>maxi){
                maxi=nums[k];
                idx=k;
            }}
        TreeNode* root=new TreeNode(nums[idx]);
        root->left=find(nums,i,idx-1);
        root->right=find(nums,idx+1,j);
        return root;
    }
};