/**
 * preorder root->left->right
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
                stack<TreeNode*> stack;
                stack.push(root);
            
                while (!stack.empty()) {
                        TreeNode* temp = stack.top();
                        
                        res.push_back(temp->val);
                        
                        stack.pop();
                        if (temp->right) {
                                stack.push(temp->right);
                        }
                        if (temp->left) {
                                stack.push(temp->left);
                        }
                }
                return res;
        }
};