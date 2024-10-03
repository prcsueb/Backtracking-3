//time: O(mn^L) space: O(L)
class Solution {
private:
    vector<vector<char>> board;
    int ROWS;
    int COLS;

public:
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        ROWS = board.size();
        COLS = board[0].size();
        for (int row = 0; row < ROWS; ++row)
            for (int col = 0; col < COLS; ++col)
                if (backtrack(row, col, word, 0)) return true;
        return false;
    }

private:
    bool backtrack(int row, int col, const string& word, int index) {
        if (index >= word.length()) return true;
        if (row < 0 || row == ROWS || col < 0 || col == COLS ||
            board[row][col] != word[index])
            return false;
        bool ret = false;
        board[row][col] = '#';
        int rowOffsets[4] = {0, 1, 0, -1};
        int colOffsets[4] = {1, 0, -1, 0};
        for (int d = 0; d < 4; ++d) {
            ret = backtrack(row + rowOffsets[d], col + colOffsets[d], word, index + 1);
            if (ret) break;
        }
        board[row][col] = word[index];
        return ret;
    }
};