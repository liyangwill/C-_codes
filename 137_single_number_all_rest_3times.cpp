/**
 * only one num appears once, the rest all twice.
 * 
 * bitwise operator ^:  101^100 = 001, 1^1 = 0, 0^0=0;
 */
class Solution {
public:
        int singleNumber(vector<int>& nums){
                int ones = 0, twos = 0;
                for(int i=0; i<nums.size(); i++){
                        ones=(ones^nums[i]) & ~twos; // A & ~A = 0
                        twos=(twos^nums[i]) & ~ones;
                }
                return ones;
        }
};