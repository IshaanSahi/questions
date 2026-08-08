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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        queue<pair<TreeNode*,int>>q;
        int level=1;
        if(root==nullptr)
            return result;
        q.push({root,level});
        while(!q.empty()){
            TreeNode* node=q.front().first;
            if(q.front().second==level){
                level++;
                result.push_back(node->val);
            }
            q.pop();
            if(node->right!=nullptr)
                q.push({node->right,level});
            if(node->left!=nullptr)
                q.push({node->left,level});
        }
        return result;
    }
    
};