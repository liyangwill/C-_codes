/**int maxDepth(TreeNode *root)
 *{
 *        return root == NULL ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
 *}
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            res++;
            for(int i = 0; i != q.size(); ++i){
                TreeNode* p = q.front();
                q.pop();
                if(!p->left) q.push(p->left);
                if(!p->right) q.push(p->right);
            }
        }
        return res;
    }
};