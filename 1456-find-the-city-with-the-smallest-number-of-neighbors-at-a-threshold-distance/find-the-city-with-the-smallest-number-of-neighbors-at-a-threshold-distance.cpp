class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dT) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        int maxcity=n;
        int cityno=-1;
        for(int i=0;i<n;i++){
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            pq.push({0,i});
            vector<int>dist(n,INT_MAX);
            dist[i]=0;
            while(!(pq.empty())){
                int node=pq.top().second;
                int d=pq.top().first;
                pq.pop();
                for(auto it:adj[node]){
                    int x=it.second;
                    int l=it.first;
                    if(dist[l]>d+x){
                        dist[l]=d+x;
                        pq.push({dist[l],l});
                    }
                }
            }
            int cnt=0;
            for(auto it:dist){
                if(it<=dT) cnt++;
            }
            if(cnt<=maxcity){
                maxcity=min(cnt,maxcity);
                cityno=i;
            }
        }
        return cityno;
    }
};