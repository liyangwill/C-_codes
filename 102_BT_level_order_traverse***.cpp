/**
 * 
 * 
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
        vector<vector<int>> ret; //define global ret
        
        vector<vector<int>> levelOrder(TreeNode* root) {
                buildVector(root, 0);
                return ret;
        }
        //define buildVector with aid of depth
        void buildVector(TreeNode* root, int depth){
                if(root == NULL) return;
                if(ret.size() == depth)
                    ret.push_back(vector<int>());
                    //variable.push_back() allocate
                ret[depth].push_back(root->val);
                //push_back variable into depth'th vector
            
                buildVector(root->left, depth + 1);
                buildVector(root->right, depth + 1);
        }
};