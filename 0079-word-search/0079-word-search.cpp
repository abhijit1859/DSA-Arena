class Solution {
public:
    int m, n;
    vector<vector<char>> b;
    string w;
    bool exist(vector<vector<char>>& board, string word) {
        b = board;
        w = word;
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (backtrack(i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }

    bool backtrack(int i, int j, int index) {
        if(index==w.size()) return true;

        if(i<0||j<0||i>=m||j>=n||b[i][j]!=w[index]) return false;
        char temp=b[i][j];
        b[i][j]='#';
        bool found =
            backtrack(i + 1, j, index + 1) || backtrack(i - 1, j, index + 1) ||
            backtrack(i, j + 1, index + 1) || backtrack(i, j - 1, index + 1);
        
        b[i][j]=temp;
        return found;    
    }
};