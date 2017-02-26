// Input: k = 3, n = 9

// Output:  [[1,2,6], [1,3,5], [2,3,4]] all unique numbers

// DP result, solution, keep deducting n utill n == 0;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> sol;
        combination(result, sol, k, n);
        return result;
    }
    
    void combination(vector<vector<int>>& result, vector<int> sol, int k, int n) {
        if (sol.size() == k && n == 0) { result.push_back(sol); return ; }
        if (sol.size() < k) {
            
            // this for-loop is the key part!
            for (int i = sol.empty() ? 1 : sol.back() + 1; i <= 9; ++i) {
                if (n - i < 0) break;
                sol.push_back(i);
                combination(result, sol, k, n - i);
                sol.pop_back();
            }
        }
    }
};