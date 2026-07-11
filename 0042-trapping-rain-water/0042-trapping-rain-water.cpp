class Solution {
public:
    int trap(vector<int>& height) {
        int result=0,left,bottom,width,ht;
        stack<int>st;
        for(int i=0;i<height.size();i++){
            while(!st.empty() && height[i]>height[st.top()]){
                bottom=st.top();
                st.pop();
                if(st.empty())
                    break;
                left=st.top();
                width=i-1-left;
                ht=min(height[i],height[left])-height[bottom];
                result+=ht*width;
            }
            st.push(i);
        }
        return result;
    }
};