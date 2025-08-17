class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &v : edges) {
            adj[v[0]].push_back({v[2], v[1]});
            adj[v[1]].push_back({2*v[2], v[0]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // fixed typo
        vector<int> dis(n, INT_MAX);
        dis[0] = 0;
        pq.push({0,0});

        while (!(pq.empty())) {
            auto x = pq.top();
            pq.pop();
            int d = x.first;
            int node = x.second;

            if (d > dis[node]) continue;  

            for (auto it : adj[node]) {
                if (dis[it.second] > d + it.first) {
                    dis[it.second] = d + it.first;
                    pq.push({dis[it.second], it.second});
                }
            }
        }

        if (dis[n-1] == INT_MAX) return -1;
        else return dis[n-1];
    }
};
