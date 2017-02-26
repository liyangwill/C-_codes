// quick sort
// 1. Initialize left to be 0 and right to be nums.size() - 1;
// 2. Partition the array, if the pivot is at the k-1-th position, return it (we are done);
// 3. If the pivot is right to the k-1-th position, update right to be the left neighbor of the pivot;
// 4. Else update left to be the right neighbor of the pivot.
// 5. Repeat 2.

class Solution {
public:
    //partition: o(n)
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot)
                swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot) l++;
            if (nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
    //T(n)=T(n/2)+o(n), T(n)=nlogn;
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
};
