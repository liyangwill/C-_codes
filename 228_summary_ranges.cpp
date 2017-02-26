
// [1 2 3 5 6 7]: [1->3 5-7>]
// to_string(int)

class Solution{
    vector<string> summaryRanges(vector<int>& nums){
        const int n = nums.size();
        vector<string> res;
        if (n == 0) {
            return res;
        }
        for (int i = 0; i < n; i++) {
            int start = i; end = i;
            while (end + 1 < n && nums[end+1] == nums[end] + 1) end ++;
            if(end > start) res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            else res.push_back(to_string(nums[start]));
            i = end + 1;
        }
        return res;
    }
};