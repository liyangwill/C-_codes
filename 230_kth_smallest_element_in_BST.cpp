// inorder traverse, decrease k at each node
//
// when k = 0, find the element

int kthSmallest(TreeNode* root, int k) {
    return find(root, k);
}
int find(TreeNode* root, int& k) {
    if (root) {
        int x = find(root->left, k);
        if (!k) {
            return x;
        }else if(!--k){
            return root->val;
        } else return find(root->right, k);
    }
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        TreeNode *p = root;
        while(p || !st.empty())
        {
            while(p)
            {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            if(--k == 0)
                return p->val;
            st.pop();
            p = p->right;
        }
    }
};