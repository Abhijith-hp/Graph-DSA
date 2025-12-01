class Solution {
  public:
     void dfs(int sr,int sc,int initColor,int color,vector<vector<int>>&ans,vector<vector<int>>&image,int delRow[],int delCol[]){
           ans[sr][sc]= color;
           int m = image.size();
           int n = image[0].size();

           for(int i=0;i<4;i++){
               int nRow = sr + delRow[i];
               int nCol = sc + delCol[i];
               if(nRow>=0 && nCol>=0 && nRow<m && nCol<n && ans[nRow][nCol]!=color && image[nRow][nCol]==initColor){
                dfs(nRow,nCol,initColor,color,ans,image,delRow,delCol);
               }
           }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int initColor = image[sr][sc];
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1}; 

        vector<vector<int>> ans = image;
        dfs(sr,sc,initColor,newColor,ans,image,delRow,delCol);
        return ans;
        
    }
};