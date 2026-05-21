class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
      
        vector<string> board(n, string(n, '.'));
        
    
        unordered_set<int> cols;
        unordered_set<int> posDiag;
        unordered_set<int> negDiag;
        
        backtrack(0, n, board, ans, cols, posDiag, negDiag);
        return ans;
    }

private:
    void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& ans,
                   unordered_set<int>& cols, unordered_set<int>& posDiag, unordered_set<int>& negDiag) {
       
        if (row == n) {
            ans.push_back(board);
            return;
        }
        
        
        for (int col = 0; col < n; col++) {
           
            if (cols.count(col) || posDiag.count(row + col) || negDiag.count(row - col)) {
                continue;
            }
            
          
            board[row][col] = 'Q';
            cols.insert(col);
            posDiag.insert(row + col);
            negDiag.insert(row - col);
            
           
            backtrack(row + 1, n, board, ans, cols, posDiag, negDiag);
            
           
            board[row][col] = '.';
            cols.erase(col);
            posDiag.erase(row + col);
            negDiag.erase(row - col);
        }
    }
};
