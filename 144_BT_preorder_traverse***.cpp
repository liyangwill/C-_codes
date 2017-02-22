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
                        return vector<int>(); //define a null vector of int
                }
                vector<int> result;
                stack<TreeNode *> treeStack;  
                treeStack.push(root);
                while (!treeStack.empty()) {
                        TreeNode *temp = treeStack.top();
                        
                        result.push_back(temp->val); // push_back to result vector
                        
                        treeStack.pop();
                        if (temp->right) {
                                treeStack.push(temp->right);
                        }
                        if (temp->left) {
                                treeStack.push(temp->left);
                        }
                }
                return result;
        }
};