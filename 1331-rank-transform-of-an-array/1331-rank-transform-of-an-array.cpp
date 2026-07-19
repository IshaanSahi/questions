class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>array=arr;
        unordered_map<int,int>mp;
        int rank=0,prev=INT_MIN;
        sort(array.begin(),array.end());
        for(int element:array){
            if(element>prev)
                rank++;
            mp.insert({element,rank});
            prev=element;
        }
        for(int i=0;i<arr.size();i++){
            array[i]=mp[arr[i]];
        }
        return array;
    }
};