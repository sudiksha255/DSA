class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ROWS=matrix.size();
        int COLS=matrix[0].size();
        int col1=1;

        for(int r=0;r<ROWS;r++){
          
            if(matrix[r][0]==0){
                col1=0;
            }

            for(int c=1;c<COLS;c++){
                if(matrix[r][c]==0){
                    matrix[r][0]=0;
                    matrix[0][c]=0;
                }
            }
        }
        for(int r=ROWS-1;r>=0;r--){
            for(int c=COLS-1;c>=1;c--){
                if(matrix[r][0]==0||matrix[0][c]==0){
                    matrix[r][c]=0;
                }
            }
            if(col1==0){
                matrix[r][0]=0;
            }
        }


    }
};