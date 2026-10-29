class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>set;
        unordered_set<int>res;
        for(auto it:nums1){
            set.insert(it);
        }
        for(auto it:nums2){
            if(set.find(it)!=set.end())
                res.insert(it);
        }
        vector<int>final;
        for(auto it:res){
            final.push_back(it);
        }
        return final;
    }
};