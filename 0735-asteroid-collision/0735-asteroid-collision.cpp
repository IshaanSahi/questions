class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>result;
        int n=asteroids.size(),ast,top,ans;
        bool in=true;
        for(int i=0;i<n;i++){
            ast=asteroids[i];
            if(ast>0)
                st.push(ast);
            else{
                while(!st.empty() && st.top()>0 && st.top()<abs(ast)){
                    st.pop();
                }
                if(!st.empty() && st.top()==abs(ast))
                    st.pop();
                else if(st.empty() || st.top()<0)
                    st.push(ast);
            }
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};