class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int>result;
        vector<vector<int>>adj(V);
        vector<int> indegree(V, 0); 
       for (auto &e : edges) {
             adj[e[0]].push_back(e[1]);
        }
        for(int i=0;i<V;i++){
          for(auto next: adj[i]){
              indegree[next]++;
          } 
        }
        
        queue<int>tempNodes;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) tempNodes.push(i);
        }
        
        while(!tempNodes.empty()){
            int node = tempNodes.front();
            result.push_back(node);
            tempNodes.pop();
            for(auto nextNode: adj[node]){
                indegree[nextNode]--;
                if (indegree[nextNode] == 0)
                  tempNodes.push(nextNode);
            }
            
        }
        
    return result;
    }
};