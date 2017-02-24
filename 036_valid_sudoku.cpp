/**
 *  return if a sudoku is valid.
 *  bit operator & : 3(011)&5(101) = 1(001)
 *  bit operator | : 3(011)|5(101) = 7(111)
 * O(n^2)
 */

class Solution {
public:
        bool isValidSudoku(vector<vector<char>>& board) {
                // 0
                vector<short> col(9, 0);
                vector<short> block(9, 0);
                vector<short> row(9, 0);
                for (int i = 0; i < 9; i++)
                        for (int j = 0; j < 9; j++) {
                                if (board[i][j] != '.') {
                                        // convert char to numer with bit shift
                                        int idx = 1 << (board[i][j] - '0');
                                        if (row[i] & idx || col[j] & idx || block[i/3 * 3 + j / 3] & idx)
                                                return false;
                                        row[i] |= idx; // add board[i][j] to row check
                                        col[j] |= idx; // add board[i][j] to col check
                                        block[i/3 * 3 + j/3] |= idx; // add board[i][j] to bloack check
                                }
                        }
                return true;
        }
};