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
    int maxfreq=0;
    int freq=0,count=0,prev=0;
    bool first=true;
    vector<int>result;
    vector<int> findMode(TreeNode* root) {
        find(root);
        return result;
    }
    void find(TreeNode *root){
        if(root==nullptr)
            return ;
        find(root->left);
        if(first || root->val!=prev){
            count=1;
            first=false;
        }
        else {
            count++;
        }
        if(count>maxfreq){
            maxfreq=count;
            result.clear();
            result.push_back(root->val);
        }
        else if(count==maxfreq)
            result.push_back(root->val);
        prev=root->val;
        find(root->right);
    }
};