class solution {
public:
        int depth (TreeNode *root) { //DP search the depth of BT
                if (root == NULL) return 0;
                return max (depth(root -> left), depth (root -> right)) + 1;
        }
        
        bool isBalanced (TreeNode *root) {
                if (root == NULL) return true;
                
                int left=depth(root->left); 
                int right=depth(root->right);
                // check depth of left and right subtress, and if they are balanced.
                return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        }
};