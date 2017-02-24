class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], sum = 0;
        for(int i = 0; i != nums.size(); ++i){
            sum += nums[i];
            ans = max(sum, ans);
            // sum = 0 means to ignore subarray before
            sum = max(sum, 0);
        }
        return ans;
    }
    
};