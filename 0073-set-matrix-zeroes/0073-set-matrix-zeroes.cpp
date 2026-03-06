class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows(matrix.size(),0);
        vector<int> cols(matrix[0].size(),0);

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();i++){
                if(matrix[i][j]==0){
                    rows[i]=1;
                    cols[i]=1;
                }
            }
        }

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();i++){
                if(rows[i]||cols[i]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};