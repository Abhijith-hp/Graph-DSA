class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        if(grid[0][0]!=0 || grid[m-1][n-1]!=0)
              return -1;
        queue<pair<int,pair<int,int>>> tempQueue;
        dist[0][0] = 1;
        tempQueue.push({1,{0,0}});
        
        int dr[8] = {-1,-1,-1, 0,0, 1,1,1};
        int dc[8] = {-1, 0, 1,-1,1,-1,0,1};

        while(!tempQueue.empty()){
            auto it = tempQueue.front();
            int distance = it.first;
            int row = it.second.first;
            int col = it.second.second;
            tempQueue.pop();
            if(row==m-1 && col==n-1) return distance;
            for(int i=0;i<8;i++){
                int newRow = row + dr[i];
                int newCol = col+ dc[i];

                if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && grid[newRow][newCol]==0 &&
                   dist[row][col]+1  < dist[newRow][newCol]){
                    
                   dist[newRow][newCol] = dist[row][col] + 1;
                   tempQueue.push({dist[newRow][newCol],{newRow,newCol}});
                   }
            }
        }
        return -1;
    }
};