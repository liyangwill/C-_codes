// ordered _set
// The basic idea is to maintain a set s
// which contain unique values from nums[i - k] to nums[i - 1],
// if nums[i] is in set s then return true else update the set.

// two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

// #include<unordered_set>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k, int t)
    {
        set<int> window;
        for (int i = 0; i < nums.size(); i++) {
        
            if (i > k) window.erase(nums[i-k-1]);
            // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
            // x-nums[i] >= -t ==> x >= nums[i]-t
            auto pos = window.lower_bound(nums[i] - t);
            // x - nums[i] <= t ==> |x - nums[i]| <= t
            if (pos != window.end() && *pos - nums[i] <= t)
                return true;
            window.insert(nums[i]);
        }
        return false;
    }
};