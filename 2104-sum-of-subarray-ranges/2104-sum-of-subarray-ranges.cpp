class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int>lsi(n),rsi(n),lgi(n),rgi(n);
        stack<int>st;
        long long total=0;
        for(int i=n-1;i>=0;i--){
            //rsi
            while(!st.empty()){
                if(nums[st.top()]<=nums[i]){
                    rsi[i]=st.top();
                    break;
                }
                else
                    st.pop();
            }
            if(st.empty())
                rsi[i]=n;
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i=0;i<n;i++){
            //lsi
            while(!st.empty()){
                if(nums[st.top()]<nums[i]){
                    lsi[i]=st.top();
                    break;
                }
                else
                    st.pop();
            }
            if(st.empty())
                lsi[i]=-1;
            st.push(i);
        }
        while(!st.empty())
            st.pop();

        for(int i=n-1;i>=0;i--){
            //rgi
            while(!st.empty()){
                if(nums[st.top()]>=nums[i]){
                    rgi[i]=st.top();
                    break;
                }
                else
                    st.pop();
            }
            if(st.empty())
                rgi[i]=n;
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        
        for(int i=0;i<n;i++){
            //lgi
            while(!st.empty()){
                if(nums[st.top()]>nums[i]){
                    lgi[i]=st.top();
                    break;
                }
                else
                    st.pop();
            }
            if(st.empty())
                lgi[i]=-1;
            st.push(i);
        }

        for(int i=0;i<n;i++){
            total+=1LL*nums[i]*(1LL*(i-lgi[i])*(rgi[i]-i)-1LL*(i-lsi[i])*(rsi[i]-i));
        }
        return total;
    }
};