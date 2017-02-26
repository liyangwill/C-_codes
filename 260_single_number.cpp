class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        
        // int diff=0;
        // for (int i=0; i!=nums.size();i++){
        //      diff ^= nums[i];
        //}
        // Get its last set bit
        // 2[11]^(-2)[11000001]=[11000010]
        diff &= -diff;
        
        // Pass 2 :
        vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
        for (int num : nums)
        {
            if ((num & diff) == 0) // the bit is not set
            {
                rets[0] ^= num;
            }
            else // the bit is set
            {
                rets[1] ^= num;
            }
        }
        return rets;
    }
};