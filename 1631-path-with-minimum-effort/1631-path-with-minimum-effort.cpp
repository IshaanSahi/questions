
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
 
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;
 
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
 
        vector<int> delr = {0, -1, 0, 1};
        vector<int> delc = {1, 0, -1, 0};

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()) {

            int effort = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if(effort > dist[r][c])
                continue;

            if(r == n-1 && c == m-1)
                return effort;

            for(int i = 0; i < 4; i++) {

                int nr = r + delr[i];
                int nc = c + delc[i];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m) {

                    int diff = abs(heights[nr][nc] - heights[r][c]);

                    int newEffort = max(effort, diff);

                    if(newEffort < dist[nr][nc]) {

                        dist[nr][nc] = newEffort;

                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};
