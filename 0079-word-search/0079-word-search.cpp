class Solution {
public:
    bool dfs(int row, int col, int idx, vector<vector<char>>& board, string &word) {

        if (idx == word.size())
            return true;

        int m = board.size();
        int n = board[0].size();

        if (row < 0 || row >= m || col < 0 || col >= n)
            return false;

        if (board[row][col] != word[idx])
            return false;

        char temp = board[row][col];
        board[row][col] = '#';

        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if (dfs(newRow, newCol, idx + 1, board, word))
                return true;
        }

        board[row][col] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (dfs(i, j, 0, board, word))
                    return true;
            }
        }

        return false;
    }
};