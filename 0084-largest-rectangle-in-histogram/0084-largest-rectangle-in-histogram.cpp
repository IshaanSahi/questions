class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(),max_area=0;
        stack<int>st;
        vector<int>lse(n),rse(n),area(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty())
                rse[i]=n;
            else
                rse[i]=st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                st.pop();
            }
            if(st.empty())
                lse[i]=-1;
            else
                lse[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            area[i]=(rse[i]-lse[i]-1)*heights[i];
            max_area=max(area[i],max_area);
        }
        return max_area;
    }
};