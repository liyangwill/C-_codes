// number with length of n
// DP create

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        unordered_map<char, char> map{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        vector<string> res;
        string str(n, ' ');
        helper(res, str, 0, n - 1, map);
        return res;
    }
private:
    void helper(vector<string>& res, string& s, int start, int end, unordered_map<char, char>& map) {
        if (start > end) {
            res.push_back(s);
            return;
        }
        
        for (auto &m : map) {
            if (s.length() > 1 && start == 0 && m.first == '0') {
                continue;
            }
            if (start == end && (m.first == '6' || m.first == '9')) {
                continue;
            }
            s[start] = m.first;
            s[end] = m.second;
            helper(res, s, start + 1, end - 1, map);
        }
    }
};