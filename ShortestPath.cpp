    // User function Template for C++
    class Solution {
      public:
        void dfs(int node,vector<int>&visited,stack<int>&st,vector<vector<pair<int,int>>> &adj){
            visited[node] = true;
            for(auto nextNodes: adj[node]){
                int nextNode = nextNodes.first;
                if(!visited[nextNode])
                    dfs(nextNode,visited,st,adj);
            }
            st.push(node);
            
        }
        vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
           
          vector<vector<pair<int,int>>> adj(V);
          vector<int> visited(V,0);
           for(int i=0;i<E;i++){
               int u = edges[i][0];
               int v = edges[i][1];
               int w = edges[i][2];
               adj[u].push_back({v,w});
               
           }
           
           stack<int>st;
           vector<int> dist(V, 1e9);
           dist[0] = 0;
           for(int i=0;i<V;i++){
               if(!visited[i]){
                   dfs(i,visited,st,adj);
               }
           }
           
           while(!st.empty()){
               int node = st.top();
               st.pop();
               for(auto nextNodes: adj[node]){
                   int weight = nextNodes.second;
                   int nextNode = nextNodes.first;
                  if(dist[node] + weight < dist[nextNode]) {
                        dist[nextNode] = dist[node] + weight;
                    }
    
               }
           }
           for(int i = 0; i < V; i++){
                if(dist[i] == 1e9) dist[i] = -1;
            }

           return dist; 
        }
    };
