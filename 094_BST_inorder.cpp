/**
 * return inorder traversal
 * inorder: left->root->right
 * using a stack
 */
class Solution {
public:
        vector<int> inorderTraversal(TreeNode* root) {
            if (root==NULL) {
                return vector<int>(); //define a null vector of int
            }

            vector<int> res;
            stack<TreeNode*> stack;
            TreeNode* cur = root;
                
            while(!stack.empty() || cur)
            {
                    if(cur)
                    {
                            stack.push(cur);
                            cur = cur->left;
                    }
                    else
                    {
                            TreeNode* temp = stack.top();
                            res.push_back(temp->val);
                            stack.pop();
                            cur = temp->right;
                    }
            }
        return res;
        }
};