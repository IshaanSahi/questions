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

    int countNodes(TreeNode* root) {
        int hl,hr;
        if(root==nullptr)
            return 0;
        hl=leftHeight(root->left);
        hr=rightHeight(root->right);
        if(hl==hr)
            return (1 << (hl + 1)) - 1;
        else{
            return 1+countNodes(root->left)+countNodes(root->right);
        }    
    }
    int leftHeight(TreeNode* root) {
    int h = 0;

    while(root) {
        h++;
        root = root->left;
    }

    return h;
}
int rightHeight(TreeNode* root) {
    int h = 0;

    while(root) {
        h++;
        root = root->right;
    }

    return h;
}


    // int countNodes(TreeNode* root) {
    //     int count=0,level=0,size;
    //     queue<TreeNode*>q;
    //     if(root!=nullptr)
    //         q.push(root);
    //     while(!q.empty()){
    //         size=q.size();
    //         count+=size;
    //         for(int i=0;i<size;i++){
    //             TreeNode* node=q.front();
    //             q.pop();
    //             if(node->left!=nullptr)
    //                 q.push(node->left);
    //             if(node->right!=nullptr)
    //                 q.push(node->right);
    //         }
    //     }
    //     return count;
    // }
};