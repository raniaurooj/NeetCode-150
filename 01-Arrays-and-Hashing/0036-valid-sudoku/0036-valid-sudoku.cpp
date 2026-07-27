class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols, boxes;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;

                int box = (i / 3) * 3 + (j / 3); // box index 0–8

                if (rows[i].count(c) || cols[j].count(c) || boxes[box].count(c))
                    return false;

                rows[i].insert(c);
                cols[j].insert(c);
                boxes[box].insert(c);
            }
        }
        return true;
    }
        
};