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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len=inorder.size(),pos=0;
        if(inorder.size()==0 || postorder.size()==0)
            return nullptr;
        TreeNode* root=new TreeNode(postorder[len-1]);
        for(pos=0;pos<len;pos++){
            if(postorder[len-1]==inorder[pos])
                break;
        }
        vector<int>inLeft(inorder.begin(),inorder.begin()+pos);
        vector<int>inRight(inorder.begin()+pos+1,inorder.end());
        vector<int>postLeft(postorder.begin(),postorder.begin()+pos);
        vector<int>postRight(postorder.begin()+pos,postorder.end()-1);
        root->left=buildTree(inLeft,postLeft);
        root->right=buildTree(inRight,postRight);
        return root;
    }
};