/**
 * postorder reverse(root->rigth->left)  left->right->root
 * 
 * use stack, stack.pop(), stack.top()
 * 
 */
class Solution {
public:
        vector<int> preorderTraversal(TreeNode *root) {
                if (root==NULL) {
                        return vector<int>();
                }
                vector<int> res;
                stack<TreeNode *> stack;
                stack.push(root);
                
                while (!stack.empty()) {
                        TreeNode *temp = stack.top();
                        
                        res.push_back(temp->val);
                        stack.pop();
                        if (temp->left) {
                                stack.push(temp->left);
                        }
                        if (temp->right) {
                                stack.push(temp->right);
                        }
                }
                reverse(res.begin(),result.end());
                return res;
        }
};