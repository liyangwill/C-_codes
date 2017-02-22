class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0, end=num.size()-1;
        
        while(start<end) {
            if (nums[start]<nums[end])
                return nums[start];
            
            int mid = (start+end)/2;
        
            if (nums[mid]>nums[start]) {
                start = mid+1;
            } else if (nums[mid]<nums[start]){
                end = mid;
            } else start = mid;
        }
        return nums[start];
    }
};