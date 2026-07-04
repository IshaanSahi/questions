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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result=nullptr;
        stack<int>list1,list2;
        int carry=0,sum=0;
        while(l1){
            list1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            list2.push(l2->val);
            l2=l2->next;
        }
        while(!list1.empty() || !list2.empty() || carry){
            sum=carry;
            if(!list1.empty()){
                sum+=list1.top();
                list1.pop();
            }
            if(!list2.empty()){
                sum+=list2.top();
                list2.pop();
            }
            carry=sum/10;
            sum%=10;
            ListNode* newnode=new ListNode(sum);
            newnode->next=result;
            result=newnode;
        }
        return result;
    }
};