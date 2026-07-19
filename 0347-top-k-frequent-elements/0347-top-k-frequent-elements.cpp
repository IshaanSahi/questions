struct compare{
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        return a.second>b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>result;
        for(auto it:nums){
            mp[it]++;
        }
        vector<pair<int,int>>vec;
        for(auto it:mp){
            vec.push_back({it.first,it.second});
        }
        sort(vec.begin(),vec.end(),compare());
        for(int i=0;i<k;i++){
            result.push_back(vec[i].first);
        }
        return result;
    }
};