class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int cnt=0;queue<int>q;
        vector<int>res;
        vector<int>inorder(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(auto it:adj){
            for(auto j:it)
                inorder[j]++;
        }
        for(int i=0;i<numCourses;i++){
            if(inorder[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            cnt++;
            res.push_back(node);
            q.pop();
            for(auto it:adj[node]){
                inorder[it]--;
                if(inorder[it]==0)
                    q.push(it);
            }
        }
        if(cnt!=numCourses){
            return {};
        }
        return res;
    }
};