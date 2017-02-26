class Solution{
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(!root) return result;
        
        helper(result, root, to_string(root->val));
        return result;
    }
    
    void helper(vector<string>& result, TreeNode* root, string t) {
        if(!root->left && !root->right) {
            result.push_back(t);
            return;
        }
        
        //DFS
        if(root->left) binaryTreePaths(result, root->left, t+"->"+to_string(root->left->val));
        if(root->right) binaryTreePaths(result, root->right, t+"->"+to_string(root->right->val));
    }
};