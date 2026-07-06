class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(),left=0,maxSize=0;
        set<char>subset;
        for(int right=0;right<n;right++){
            while(subset.find(s[right])!=subset.end()){
                subset.erase(s[left]);
                left++;
            }
            subset.insert(s[right]);
            maxSize=max(maxSize,right-left+1);
        }
        return maxSize;
    }
};