class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        
        unordered_map<char, int> m;
        
        string t = "", mid = "";
        
        for (auto a : s) ++m[a];
        
        // if fewer than one char appear odd times.
        for (auto it : m) {
            if (it.second % 2 == 1) mid += it.first;
            t += string(it.second/2, it.first);
            if (mid.size() > 1) return {};
        }
        permute(t, 0, mid, res);
        return res;
    }
    
    void permute(string &t, int start, string mid, vector<string> &res) {
        
        if (start >= t.size()) {
            res.push_back(t + mid + string(t.rbegin(), t.rend()));
        }
        
        // llok for permutation
        for (int i = start; i < t.size(); ++i) {
            if (i != start && t[i] == t[start]) continue;
            swap(t[i], t[start]);
            permute(t, start + 1, mid, res);
            swap(t[i], t[start]);
        }
    }
};