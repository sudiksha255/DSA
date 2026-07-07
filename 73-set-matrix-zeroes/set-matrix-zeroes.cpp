class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ROWS=matrix.size();
        int COLS=matrix[0].size();
        vector<int>row(ROWS,0);
        vector<int>col(COLS,0);

        for(int r=0;r<ROWS;r++){
            for(int c=0;c<COLS;c++){
                if(matrix[r][c]==0){
                    row[r]=1;
                    col[c]=1;
                }
            }
        }
        for(int r=0;r<ROWS;r++){
            for(int c=0;c<COLS;c++){
                if(row[r]==1||col[c]==1){
                    matrix[r][c]=0;
                }
            }
        }


    }
};