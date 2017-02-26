/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p == NULL) return NULL;
        TreeNode *res = NULL;
        if (p->right != NULL) {
            res = p->right;
            while (res->left) res = res->left;
            return res;
        }
        
        TreeNode *q = root;
        
        while (q != NULL && q->val != p->val) {
            if (q->val > p->val) {
                res = q;
                q = q->left;
            } else {
                q = q->right;
            }
        }
        return res;
    }
};