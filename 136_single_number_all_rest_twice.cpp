/**
 * only one num appears once, the rest all twice.
 * 
 * bitwise operator ^:  101^100 = 001, 1^1 = 0, 0^0=0;
 */
class Solution {
public:
        int singleNumber(vector<int>& nums){
                int n = nums.size();
                if(!n) return -1;
                
                int result = 0;
                for(int i=0; i!=n; ++i){
                        result ^= nums[i]; // ^ twice counteracts A^A = 0;
                }
                return result;    
        }
};