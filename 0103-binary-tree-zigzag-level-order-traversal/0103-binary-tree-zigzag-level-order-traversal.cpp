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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        queue<TreeNode*>q;
        int l_no=0;
        if(root==nullptr)
            return {};
        q.push(root);
        while(!q.empty()){
            vector<int>level;
            int size=q.size();
            TreeNode* node;
            for(int i=0;i<size;i++){
                node=q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left!=nullptr)
                    q.push(node->left);
                if(node->right!=nullptr)
                    q.push(node->right);
            }
            if(l_no%2==1)
                reverse(level.begin(),level.end());
            l_no++;
            result.push_back(level);
        }
        return result;
    }
};