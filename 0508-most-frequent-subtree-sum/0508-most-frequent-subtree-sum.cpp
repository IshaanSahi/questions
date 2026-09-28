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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int ,int >mp;
        int maxfreq=0;
        vector<int>ans;
        findSum(root,mp);
        for(auto it:mp){
            maxfreq=max(it.second,maxfreq);
        }
        for(auto it:mp){
            if(maxfreq==it.second)
                ans.push_back(it.first);
        }
        return ans;
    }
    int findSum(TreeNode* root,unordered_map<int,int>&mp){
        if(root==nullptr)
            return 0;
        int leftsum=findSum(root->left,mp);
        int rightsum=findSum(root->right,mp);
        int sum =root->val+leftsum+rightsum;
        if(mp.find(sum)==mp.end()){
            mp[sum]=1;
        }
        else{
            mp[sum]++;
        }
        return sum;
    }
};