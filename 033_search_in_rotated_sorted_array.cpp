/**
 *  Search if target exists and return index from a rotated and sorted array 
 */

class Solution {
public:
        int search(vector<int>& nums, int target) {
                int n = nums.size();
                int lo = 0,hi = n-1
            
                //find rotated index lo
                while(lo < hi){
                        int mid = (lo+hi)/2;
                        if(nums[mid]>nums[hi]) lo = mid +1;
                        else hi = mid;
                }
                int rot = lo;
            
                //binary search using real mid number nums[(mid+rot)%n]
                lo = 0; hi = n-1;
                while(lo<=hi){
                        int mid = (lo+hi)/2;
                        int realmid = (mid + rot)%n;
                        if(nums[realmid]==target) return realmid;
                        if(nums[realmid]<target) lo=mid+1;
                        else hi=mid-1;
                }
                return lo;
        }
};