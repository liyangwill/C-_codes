// unordered _set
// The basic idea is to maintain a set s
// which contain unique values from nums[i - k] to nums[i - 1],
// if nums[i] is in set s then return true else update the set.

#include<unordered_set>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_set<int> s;
        
        if (k <= 0) return false;
        if (k >= nums.size()) k = nums.size() - 1;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > k) s.erase(nums[i - k - 1]);
            //.find returns .end if not find 
            if (s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);
        }
        
        return false;
    }
};