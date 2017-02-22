/**
 *
 * DP check with two treenodes
 */
class Solution {
public:
        bool isSymmetric(TreeNode* root) {
                if (!root) return true;
                return check(root->left, root->right);
        }
        bool check(TreeNode* p, TreeNode* q){
                if (!p && !q) return true;
                else if (!p || !q) return false;
                else if (p->val != q->val) return false;
                
                return (check(p->left, q->left) && check(p->right, q->right));
        }
};