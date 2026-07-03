class Solution {
private:
void solve(int col, string s, vector<string>& board, vector<vector<string>>& ans, 
vector<int>& leftrow, vector<int>& lowerdia, vector<int>& upperdia, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for(int row = 0; row < n; row++){
        if(leftrow[row] == 0 && lowerdia[row + col] == 0 && upperdia[n-1+col-row] == 0){
            board[row][col] = 'Q';
            leftrow[row] = 1;
            lowerdia[row + col] = 1;
            upperdia[ n - 1 + col - row] = 1;
            solve(col + 1, s, board, ans, leftrow, lowerdia, upperdia, n);
            board[row][col] = '.';
            leftrow[row] = 0;
            lowerdia[row + col] = 0;
            upperdia[ n - 1 + col - row] = 0;
        }
    }

}
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i = 0; i<board.size();i++){
            board[i] = s;
        }
        vector<int>leftrow(n,0);
        vector<int>lowerdia(2*n-1,0);
        vector<int> upperdia(2*n-1,0);
        solve(0,s,board,ans,leftrow,lowerdia,upperdia,n);
        return ans;
    }
};
