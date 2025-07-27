class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {src, 0}});
        dist[src] = 0;

        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();

            int stops = x.first;
            int node = x.second.first;
            int d = x.second.second;

            if (stops > k) continue;

            for (auto it : adj[node]) {
                if (dist[it.first] >= d + it.second) {
                    dist[it.first] = d + it.second;
                    pq.push({stops+1, {it.first, dist[it.first]}});
                }
            }
        }

        if (dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};
