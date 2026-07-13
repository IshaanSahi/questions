class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int>st;
        vector<int>nextG(n),result(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i])
                st.pop();
            if(st.empty())
                nextG[i]=n;
            else
                nextG[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            if(nextG[i]==n){
                result[i]=0;
            }
            else{
                result[i]=nextG[i]-i;
            }
        }
        return result;
    }
};