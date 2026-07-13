class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<int> vis(V, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int,int>>> pq;
        int cost = 0;
        pq.push({0,0});
        while(!pq.empty()){
            int dist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(vis[u] == 1) continue;
            vis[u] = 1;

            cost += dist;

            for(int v = 0; v<V; v++){
                if(!vis[v]){
                    int wt = abs(points[u][0] - points[v][0]) 
                        + abs(points[u][1] - points[v][1]);

                    pq.push({wt, v});
                }
            }

        }

        return cost;
    }
};
