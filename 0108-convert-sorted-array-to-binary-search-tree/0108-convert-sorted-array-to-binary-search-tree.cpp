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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int end=nums.size()-1;
        return find(nums,0,end);
    }
    TreeNode* find(vector<int>&nums,int st,int end){
        if(st>end)
            return nullptr;
        int mid=(st+end)/2;
        TreeNode* node= new TreeNode(nums[mid]);
        node->left=find(nums,st,mid-1);
        node->right=find(nums,mid+1,end);
        return node;
    }
};