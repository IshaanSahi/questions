class Solution {
public:
    int reverseDegree(string s) {
        int len=s.length(),ans=0;
        while(len>0){
            ans+=len*((int)'z'-(int)s[len-1]+1);
            len--;
        }
        return ans;
    }
};