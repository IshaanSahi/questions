/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int count=0;
        unordered_map<TreeNode*,TreeNode*>parent;
        unordered_set<TreeNode*>visited;
        queue<TreeNode*>q;
        vector<int>result;
        findParent(root,parent);
        q.push(target);
        visited.insert(target);
        while(count<k){
                int size=q.size();
                for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=nullptr && !visited.count(node->left)){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right!=nullptr && !visited.count(node->right)){
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if(parent.count(node) && !visited.count(parent[node])) {
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                    }
                }
                count++;
        }
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            result.push_back(node->val);
        }
        return result;
    }
    void findParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
        if(root==nullptr)
            return ;
        if(root->left!=nullptr)
            parent[root->left]=root;
        if(root->right!=nullptr)
            parent[root->right]=root;
        findParent(root->left,parent);
        findParent(root->right,parent);
    }
};