class Solution {
    void nextPermutation(vector<int>& nums) {
        int k = -1;
        // Find the largest index k such that nums[k] < nums[k + 1]
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                k = i;
                break;
            }
        }
        // if array is in descending order, (3, 2, 1) -> (1, 2 ,3)
        if (k == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Find the largest index l greater than k such that nums[k] < nums[l].
        int l = -1;
        for (int i = nums.size() - 1; i > k; i--) {
            if (nums[i] > nums[k]) {
                l = i;
                break;
            }
        }
        // Swap the value of nums[k] with that of nums[l]
        swap(nums[k], nums[l]);
        
        // Reverse the sequence from nums[k + 1] to the end
        reverse(nums.begin() + k + 1, nums.end()); 
    }
};