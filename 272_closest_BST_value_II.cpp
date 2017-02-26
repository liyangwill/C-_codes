// inorder traverse, and find k integers in the 1D vector
class Solution1 {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res, v;
        inorder(root, v);
        int idx = 0;
        double diff = numeric_limits<double>::max();
        
        for (int i = 0; i < v.size(); ++i) {
            if (diff >= abs(target - v[i])) {
                diff = abs(target - v[i]);
                idx = i;
            }
        }
        int left = idx - 1, right = idx + 1;
        for (int i = 0; i < k; ++i) {
            res.push_back(v[idx]);
            if (left >= 0 && right < v.size()) {
                if (abs(v[left] - target) > abs(v[right] - target)) {
                    idx = right;
                    ++right;
                } else {
                    idx = left;
                    --left;
                }
            } else if (left >= 0) {
                idx = left;
                --left;
            } else if (right < v.size()) {
                idx = right;
                ++right;
            }
        }
        return res;
    }
    void inorder(TreeNode *root, vector<int> &v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
};

// select k values while inorder traverse
// if abs(root->val - target) < abs(res[0] - target), root->val is closer to target, erase head int, and push_back root->val
// if else search is done.


class Solution2 {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        inorder(root, target, k, res);
        return res;
    }
    void inorder(TreeNode *root, double target, int k, vector<int> &res) {
        if (!root) return;
        inorder(root->left, target, k, res);
        
        if (res.size() < k) res.push_back(root->val);
        else if (abs(root->val - target) < abs(res[0] - target)) {
            res.erase(res.begin());
            res.push_back(root->val);
        } else return;
        inorder(root->right, target, k, res);
    }
};