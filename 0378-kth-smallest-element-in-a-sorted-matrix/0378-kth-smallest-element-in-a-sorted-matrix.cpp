class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l=matrix.size(),b=matrix[0].size(),cnt=0;
        priority_queue<int>pq;
        for(int i=0;i<l;i++){
            for(int j=0;j<b;j++){
                if(cnt<k){
                    pq.push(matrix[i][j]);
                    cnt++;
                }
                else{
                    if(pq.top()>matrix[i][j]){
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        }
        return pq.top();
    }
};