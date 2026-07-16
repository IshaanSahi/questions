class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        sort(nums.begin(),nums.end());
        for(int it:nums){
            mp[it]++;
        }
        for(int it:nums){
            if(mp[it]==0)
                continue;
            for(int i=0;i<k;i++){
                if(mp[it+i]==0)
                    return false;
                mp[it+i]--;
            }
        }
        return true;
    }
};