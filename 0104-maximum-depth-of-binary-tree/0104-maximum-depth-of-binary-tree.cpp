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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// class Solution {
// public:
//     int maxdepth=0;
//     int maxDepth(TreeNode* root) {
//         depth(root,0);
//         return maxdepth;
//     }
//     void depth(TreeNode* root,int height){
//         if(root==nullptr){
//             maxdepth=max(height,maxdepth);
//             return;
//         }
//         depth(root->left,height+1);
//         depth(root->right,height+1);
//     }
// };