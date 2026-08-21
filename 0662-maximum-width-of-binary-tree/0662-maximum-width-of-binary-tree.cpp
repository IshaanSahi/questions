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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int left,right,size,width=0;
        while(!q.empty()){
            size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front().first;
                long long idx=q.front().second;
                if(i==0)
                    left=idx;
                if(i==size-1){
                    right=idx;
                    width=max(width,right-left+1);
                }
                q.pop();
                if(node->left!=nullptr)
                    q.push({node->left,2*idx+1});
                if(node->right!=nullptr)
                    q.push({node->right,2*idx+2});
            }
        }
        return width;
    }
};