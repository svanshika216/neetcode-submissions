class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        for(auto it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, 
        greater<pair<int,int>>> pq;
        pq.push({0,k});

        while(!pq.empty()){
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(time > dist[node]) continue;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgW = it.second;
                int newTime = time + edgW;
                if(newTime < dist[adjNode]){
                    dist[adjNode] = newTime;
                    pq.push({newTime, adjNode});
                }
            }
        }
        int answer = 0;
        for(int i = 1 ; i < n + 1; i++){
            if(dist[i] == 1e9) return -1;
            answer = max(answer, dist[i]);
        }
        return answer;
    }
};
