// Input  : str[] = {"acd", "dfg", "wyz", "yab", "mop","bdfh", "a", "x", "moqs"};

// Output : a x
//          acd dfg wyz yab mop
//          bdfh moqs
// All shifted strings are grouped together.

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, multiset<string>> map;
        for (auto &str : strings) {
            string base = getBase(str);
            // mapp[index].insert(str) into multiset
            map[base].insert(str);
        }
        
        vector<vector<string>> res;
        for (auto &m : map) {
            vector<string> tmp;
            for (auto &str : m.second) {
                tmp.push_back(str);
            }
            res.push_back(tmp);
        }
        return res;
    }
private:
    //shift based on first char(to a)
    string getBase(string s) {
        // char1 - char2 = int
        int diff = s[0] - 'a';
        if (diff == 0) {
            return s;
        }
        
        s[0] = 'a';
        for (int i = 1; i < s.length(); i++) {
            // char1 - int = char2
            char c = s[i] - diff;
            s[i] = c < 'a' ? c + 26 : c;
        }
        return s;
    }
};
