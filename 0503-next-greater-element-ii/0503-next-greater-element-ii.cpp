class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>result;
        unordered_map<int,int>mp;
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
            if(st.empty()){
                mp[i%n]=-1;
            }
            else 
                mp[i%n]=st.top();
            st.push(nums[i%n]);
        }
        for(int i=0;i<n;i++){
            result.push_back(mp[i]);
        }
        return result;
    }
};