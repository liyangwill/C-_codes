/**
 *  [2,3,7] returns [[2,2,3], [7]] with target = 7
 *  DP 
 */

class Solution {
public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
                sort(candidates.begin(), candidates.end());
                vector<vector<int>> res;
                vector<int> combination;
                combinationSum2(candidates, target, res, combination, 0);
                return res;
        }
private:
        void combinationSum2(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& combination, int begin){
                if (!target) { //when the sum = target, target = 0 
                        res.push_back(combination); // combine is temperary, when it is valid push it into res. 
                        return;
                }
                for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
                        combination.push_back(candidates[i]);
                        combinationSum2(candidates, target - candidates[i], res, combination, i);
                        combination.pop_back();
                }
        }
};