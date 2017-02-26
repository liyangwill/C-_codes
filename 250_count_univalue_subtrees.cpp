// brute force
// duplicate searches exist

class Solution{
public:
    int countUnivalSubtree(TreeNode* root){
        if (!root) {
            return res;
        }
        if (!isUnival(root, root->val)) ++res;
        countUnivalSubtree(root->left);
        countUnivalSubtree(root->right);
        return res;
    }
private:
    int res = 0;
    bool isUnival(TreeNode* root, int val){
        if (!root) {
            return true;
        }
        return root->val==val && isUnival(root->left, val) && isUnival(root->right, val);
    }
};

//bottom-to-top search, DFS: depth-first-search

class Solution2 {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        isUnival(root, -1, res);
        return res;
    }
    
    bool isUnival(TreeNode *root, int val, int &res) {
        if (!root) return true;
        
        if (!isUnival(root->left, root->val, res) || !isUnival(root->right, root->val, res))
            return false;
        
        if(root->val == val){
            ++res;
            return true;
        }else return false;
    }
};
