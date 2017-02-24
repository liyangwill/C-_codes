/**
 *  Search target in a range and return index vector [lo, hi], in a sorted array.
 *  binary search biased to the left or right.
 */

class Solution {
public:
        vector<int> searchRange(vector<int>& nums, int target) {
                int n = nums.size();
                int lo = 0, hi = n-1;
                vector<int> ret(2,-1);
            
                //standard binary search (biased to the left)
                while(lo < hi){
                        int mid = (lo + hi)/2;
                        if(nums[mid] < target) lo = mid + 1;
                        else hi = mid;
                }
                if(nums[lo] != target) return ret;
                else ret[0] = lo;
                
                //binary search biased to the right
                hi = n-1;
                while(lo < hi){
                        int mid = (lo + hi)/2 + 1;
                        if(nums[mid] > target) hi = mid - 1;
                        else lo = mid;
                }
                ret[1] = hi;
                return ret;
        }
};