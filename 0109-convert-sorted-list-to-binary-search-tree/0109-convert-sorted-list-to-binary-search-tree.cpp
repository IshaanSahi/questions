/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
// class Solution {
// public:
//     TreeNode* sortedListToBST(ListNode* head) {
//         vector<int>vec;
//         while(head!=nullptr){
//             vec.push_back(head->val);
//             head=head->next;
//         }
//         return find(vec,0,vec.size()-1);
//     }
//     TreeNode* find(vector<int>vec,int st,int end){
//         if(st>end)
//             return nullptr;
//         int mid=(st+end)/2;
//         TreeNode *node= new TreeNode(vec[mid]);
//         node->left=find(vec,st,mid-1);
//         node->right=find(vec,mid+1,end);
//         return node;
//     }
// };

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr)
            return nullptr;
        ListNode* end=head;
        while(end!=nullptr){
            end=end->next;
        }
        return find(head,end);
    }
    TreeNode* find(ListNode *st,ListNode *end){
        ListNode *slow=st;
        ListNode *fast=st;
        if(st==end)
            return nullptr;
        while(fast!=end && fast->next!=end){
            slow=slow->next;
            fast=fast->next->next;
        }
        TreeNode *node=new TreeNode(slow->val);
        node->left=find(st,slow);
        node->right=find(slow->next,end);
        return node;
    }
};