// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         int num,len1,len2;
//         len1=nums1.size();
//         len2=nums2.size();
//         vector<int>result;
//         int idx=len2;
//         for(int i=0; i<len1; i++){
//             num = nums1[i];
//             idx=len2;
//             for(int j=0;j<len2;j++){
//                 if(nums2[j]==num){
//                     idx=j;
//                 }
//                 if(nums2[j]<=num && j==len2-1){
//                     result.push_back(-1);
//                 }
//                 if(nums2[j]>num && j>idx){
//                     result.push_back(nums2[j]);
//                     break;
//                 }
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;

        // Find next greater element for every element in nums2
        for (int i = nums2.size() - 1; i >= 0; i--) {

            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if (st.empty())
                mp[nums2[i]] = -1;
            else
                mp[nums2[i]] = st.top();

            st.push(nums2[i]);
        }

        // Build answer for nums1
        vector<int> ans;

        for (int x : nums1) {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};