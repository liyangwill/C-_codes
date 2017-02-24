/**
 *  calculate steps jump to the end
 */

class Solution {
public:
        int jump(vector<int>& nums) {
                int n = nums.size();
            
                //chi: current level high, nhi: next level high.
                int level = 0, i = 0, chi = 0, nhi = 0;
            
                // continue scanning if there are numbers in the level
                while(chi - i + 1 > 0){
                        level++;
                        // for each number in the cuurent level
                        for(; i <= chi; i++){
                                //updata nhi
                                nhi = max(nhi, nums[i]+i);
                                // reach to the end
                                if(nhi >= n-1) return level;
                        }
                        chi = nhi;
                }
                return 0;
        }
};