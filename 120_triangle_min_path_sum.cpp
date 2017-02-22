/**
 *     [2]
 *    [3 4]
 *  [6 5 7]
 * [4 1 8 3] 
 * 
 * [4 1 8 3] -> [7 6 10 3] -> [9 10 10 3] -> [11 11 10 3] min=11
 */
class Solution {
public:
        int minimumTotal(vector<vector<int>>& triangle) {
                vector<int> mini = triangle[triangle.size()-1];
                for ( int i = triangle.size() - 2; i>= 0 ; --i )
                        for ( int j = 0; j < triangle[i].size() ; ++ j )
                                mini[j] = triangle[i][j] + min(mini[j],mini[j+1]);
                return mini[0];  // minimum sum pop to the front 
                
        }
};