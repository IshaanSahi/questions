class Solution {
public:
    int largestRectArea(vector<int>&height){
        int n=height.size(),areaM=0;
        vector<int>ls(n),rs(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && height[st.top()]>=height[i])
                st.pop();
            if(st.empty())
                ls[i]=-1;
            else
                ls[i]=st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && height[st.top()]>height[i])
                st.pop();
            if(st.empty())
                rs[i]=n;
            else
                rs[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            int area=height[i]*(rs[i]-ls[i]-1);
            areaM=max(areaM,area);
        }
        return areaM;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int r=matrix.size(),c=matrix[0].size(),max_area=0;
        vector<int> height(c,0);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='1')
                    height[j]++;
                else 
                    height[j]=0;
            }
            max_area=max(max_area,largestRectArea(height));
        }
        return max_area;
    }
};