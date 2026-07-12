class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int size=arr.size(),mod=1e9+7;
        vector<int>nse(size),pse(size);
        stack<int>st;
        long long total=0;
        for(int i=size-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(st.empty())
                nse[i]=size;
            else
                nse[i]=st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        
        for(int i=0;i<size;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            if(st.empty())
                pse[i]=-1;
            else
                pse[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<size;i++){
            total=(total+(1LL*(nse[i]-i)*(i-pse[i])*arr[i])%mod)%mod;
        }
        return total%mod;
    }
};