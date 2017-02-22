// define two new parameters: start, end
// DP root->left and root->right

class Solution {
public:
        TreeNode* sortedArrayToBST(vector<int>& nums) {
                return sortedArrayToBST2(nums, 0,nums.size()); 
        }
        TreeNode* sortedArrayToBST2(vector<int>& nums, int start, int end){
                if(end<=start) return NULL; 
                int mid=(end+start)/2;
                TreeNode* root= new TreeNode(nums[mid]);  //create TreeNode
                root->left=sortedArrayToBST2(nums, start, mid);
                root->right=sortedArrayToBST2(nums, mid+1,end);
                return root;
        }
};