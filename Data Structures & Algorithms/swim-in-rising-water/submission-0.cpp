class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>> pq;
            int n = grid.size();
            vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
            dist[0][0] = grid[0][0];
            pq.push({grid[0][0], {0, 0}});
            while(!pq.empty()){
                auto it = pq.top();
                pq.pop();
                int cost = it.first;
                int row = it.second.first;
                int col = it.second.second;
                if(cost > dist[row][col]) continue;
                int drow[] = {-1, 0, +1, 0};
                int dcol[] = {0, +1, 0, -1};
                if(row == n-1 && col == n-1) return cost;
                for(int i = 0; i<4; i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    if(nrow < n && nrow >= 0 && ncol < n && ncol >= 0){
                        int maxcost = max(cost, grid[nrow][ncol]);
                        if( maxcost < dist[nrow][ncol]){
                            pq.push({maxcost, {nrow, ncol}});
                            dist[nrow][ncol] = maxcost;
                        }
                    }
                } 
            }
        return 0;
    }
};
