class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int num,len1,len2;
        len1=nums1.size();
        len2=nums2.size();
        vector<int>result;
        int idx=len2;
        for(int i=0; i<len1; i++){
            num = nums1[i];
            idx=len2;
            for(int j=0;j<len2;j++){
                if(nums2[j]==num){
                    idx=j;
                }
                if(nums2[j]<=num && j==len2-1){
                    result.push_back(-1);
                }
                if(nums2[j]>num && j>idx){
                    result.push_back(nums2[j]);
                    break;
                }
            }
        }
        return result;
    }
};