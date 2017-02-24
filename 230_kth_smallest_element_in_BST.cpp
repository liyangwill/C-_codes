// inorder traverse, decrease k at each node
//
// when k = 0, find the element

int kthSmallest(TreeNode* root, int k) {
    return find(root, k);
}
int find(TreeNode* root, int& k) {
    if (root) {
        int x = find(root->left, k);
        return !k ? x : (!--k ? root->val : find(root->right, k));
    }
}