class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    
        set<pair<int,int>>tempSet;
        vector<vector<pair<int,int>>>adj(V);
        vector<int>dist(V,1e9);
        
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
            
        }
        
        dist[src] = 0;
        tempSet.insert({0,src});
        while(!tempSet.empty()){
            auto element = *(tempSet.begin());
            int node = element.second;
            int distance = element.first;
            tempSet.erase(element);
            for(auto it:adj[node]){
                int weight = it.second;
                int nextNode = it.first;
                if(distance + weight < dist[nextNode]){
                    if(dist[nextNode]!=1e9){
                       tempSet.erase({dist[nextNode], nextNode});

                    }
                    dist[nextNode] = distance + weight;
                    tempSet.insert({dist[nextNode],nextNode});
                    
                }
            }
        }
        return dist;
        
    }
};