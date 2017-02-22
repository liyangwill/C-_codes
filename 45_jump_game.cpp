/**
 *  calculate steps jump to the end
 */

class Solution {
public:
        int jump(vector<int>& nums) {
                int n = nums.size();
                int level = 0, i = 0, chi = 0, nhi = 0; //chi: current level high, nhi: next level high.
                
                while(chi - i + 1 > 0){ // continue scanning if there are numbers in the level
                        level++;
                        for(; i <= chi; i++){ // for each number in the cuurent level
                                nhi = max(nhi, nums[i]+i); //updata nhi
                                if(nhi >= n-1) return level; // reach to the end
                        }
                        chi = nhi;
                }
                return 0;
        }
};