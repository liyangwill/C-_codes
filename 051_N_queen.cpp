/**
 *  vector of bitmask 
 *    | | |                / / /             \ \ \
 *    O O O               O O O               O O O
 *    | | |              / / / /             \ \ \ \
 *    O O O               O O O               O O O
 *    | | |              / / / /             \ \ \ \ 
 *    O O O               O O O               O O O
 *    | | |              / / /                 \ \ \
 *   3 columns        5 45° diagonals     5 135° diagonals    (when n is 3)
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> nQueens(n, string(n, '.'));
        vector<int> flag_col(n, 1), flag_45(2 * n - 1, 1), flag_135(2 * n - 1, 1);
        solveNQueens(res, nQueens, flag_col, flag_45, flag_135, 0, n);
        return res;
    }
private:
    void solveNQueens(vector<vector<string> > &res, vector<string> &nQueens, vector<int> &flag_col, vector<int> &flag_45, vector<int> &flag_135, int row, int &n) {
            if (row == n) {
                res.push_back(nQueens);
                return;
            }
            for (int col = 0; col != n; ++col)
                if (flag_col[col] && flag_45[row + col] && flag_135[n - 1 + col - row]) {
                        flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 0;
                        nQueens[row][col] = 'Q';
                        solveNQueens(res, nQueens, flag_col, flag_45, flag_135, row + 1, n);
                        nQueens[row][col] = '.';
                        flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 1;
                }
    }
};


int main(){
    
    Solution m;
    int n = 3;
    vector<vector<string>> res = m.solveNQueens(n);
    cout << res << endl;
}
