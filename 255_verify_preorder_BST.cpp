class Solution {
    bool verifyPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return helper(preorder, 0, n-1, INT_MIN, INT_MAX);
    }
    
    bool helper(vector<int>& preorder, int s, int e, int lb, int ub){
        
        if(s>=e) return true;
        
        // store root value in r
        int r = preorder[s];
        // r is traverse index
        int i = s;
        
        // till number larger than r
        while(i<=e && preorder[i]<=r){
            if(preorder[i]<lb || preorder[i]>ub) return false;
            i++;
        }
        // DFS
        return helper(preorder, s+1, i-1, lb, r-1) && helper(preorder, i, e, r+1, ub);
    }

};

// use a stack O(n)
class Solution2 {
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN; // lower bound
        stack<int> path;
        
        for (int p : preorder) {
            if (p < low) {
                return false;
            }
            // [ 6 2 3 4 8 7]
            while (!path.empty() && p > path.top()) {
                low = path.top();
                path.pop();
            }
            path.push(p);
        }
        return true;
    }
};