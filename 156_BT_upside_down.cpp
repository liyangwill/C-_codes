//right childern do not have sublings.

class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || !root->left) { return root; }
        
        TreeNode* newRoot = upsideDownBinaryTree(root->left); //recursive
        //    1            2
        //   / \   to     / \
        //  2   3        3   1
        root->left->left = root->right, root->left->right = root;
        root->left = NULL, root->right = NULL;
        
        return newRoot;
    }
};