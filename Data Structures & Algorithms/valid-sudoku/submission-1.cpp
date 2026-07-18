class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row = 0; row < board.size(); row++){
            unordered_set<char>seen;
            for(int col = 0; col<board.size(); col++){
                if(board[row][col] == '.') continue;
                if(seen.find(board[row][col]) != seen.end()) return false;
                seen.insert(board[row][col]);  
            }
        }
        for(int col = 0; col < board.size(); col++){
            unordered_set<char>seen;
            for(int row = 0; row<board.size(); row++){
                if(board[row][col] == '.') continue;
                if(seen.find(board[row][col]) != seen.end()) return false;
                seen.insert(board[row][col]);
            }
        }
        
        for(int row = 0; row < board.size(); row+=3){
            for(int col = 0; col <board.size(); col+=3){
                unordered_set<char>seen;
                for(int i = 0; i<3; i++){
                    for(int j = 0; j<3; j++){
                        if(board[row + i][col + j] == '.') continue;
                        if(seen.find(board[row + i][col + j]) != seen.end()) return false;
                        seen.insert(board[row + i][col + j]);
                    }
                }
            }
        }

        return true;
    }
};
