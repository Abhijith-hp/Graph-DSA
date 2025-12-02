class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<pair<int,int>,int>> tempQueues;
       
        int maxTime = 0;
         int countRotten = 0;
        int countFresh = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
             if(mat[i][j]==2){
                 tempQueues.push({{i,j},0});
            
             }
             if(mat[i][j]==1) countFresh++;
            }
        }
        while(!tempQueues.empty()){
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            int row = tempQueues.front().first.first;
            int col = tempQueues.front().first.second;
            int time = tempQueues.front().second;
            maxTime = max(maxTime,time);
            tempQueues.pop();
            for(int i=0;i<4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && mat[nRow][nCol]==1){
                    tempQueues.push({{nRow,nCol},time+1});
                    mat[nRow][nCol]=2;
                    countRotten++;
                }
            }
            
        }
       if (countRotten!=countFresh) return -1;
    return maxTime;
    }
};