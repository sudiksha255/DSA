class Solution {
public:
int rows,cols;
vector<pair<int,int>>directions={
    {1,0},{-1,0},{0,1},{0,-1}
};
void dfs(int r,int c,vector<vector<int>>&height,vector<vector<bool>>&visited){
    visited[r][c]=true;
    for(auto[dr,dc]:directions){
      int nr=r+dr;
      int nc=c+dc;
    if(nr<0||nc<0||nr>=rows||nc>=cols||visited[nr][nc]) continue;
    if(height[nr][nc]>=height[r][c]) dfs(nr,nc,height,visited);
    }
   

}


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         rows=heights.size();
         cols=heights[0].size();

        vector<vector<bool>>pacific(rows,vector<bool>(cols,false));
        vector<vector<bool>>atlantic(rows,vector<bool>(cols,false));

       //top-pacific,bottom-atlantic
        for(int c=0;c<cols;c++){
            dfs(0,c,heights,pacific);
            dfs(rows-1,c,heights,atlantic);
        }
        for(int r=0;r<rows;r++){
            dfs(r,0,heights,pacific);
            dfs(r,cols-1,heights,atlantic);
        }

        vector<vector<int>>result;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(atlantic[r][c]&&pacific[r][c]){
                    result.push_back({r,c});
                }
            }
        }
        return result;
    }
};