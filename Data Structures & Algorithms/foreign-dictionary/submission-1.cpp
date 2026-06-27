class Solution {
private: 
    vector<int> toposort(int V, vector<int> adj[]){
        vector<int> indegree(V,0);
        for(int i = 0; i<V; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0; i<V;i++){
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        return topo;
    }
public:
    string foreignDictionary(vector<string>& words) {
        unordered_set<int> chars;
        for(auto word: words)
        {
            for(auto it: word){
                chars.insert(it - 'a');
            }
        }

        vector<int> adj[26];
        for(int i = 0 ; i < words.size()-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.size(),s2.size());
            bool found = false;
            for(int ptr = 0; ptr<len; ptr++){
                if(s1[ptr] != s2[ptr]){
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    found = true;
                    break;
                }
            }

            if(!found && s1.size() > s2.size()){
                return "";
            }
        }

        vector<int> topo = toposort(26, adj);
        int cnt = 0;
        for(auto x : topo){
            if(chars.count(x)){
                cnt++;
            }
        }
        if(cnt != chars.size()){
            return "";
        }
        string ans = "";
        for(auto it: topo){
            if(chars.count(it)){
                 ans = ans + char(it + 'a');
            }
        }
        return ans;
    }
};
