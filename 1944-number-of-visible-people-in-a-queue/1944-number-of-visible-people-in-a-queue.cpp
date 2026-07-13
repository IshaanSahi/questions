class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int>rg(n),result(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            int count=0;
            while(!st.empty() && heights[st.top()]<heights[i]){
                count++;
                st.pop();
            }
            if(!st.empty())
                count++;
            result[i]=count;
            st.push(i);
        }
        return result;
    }
};