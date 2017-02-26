// string operators1: to_string()
// string operators2: int n = string.length()
// string operators3: int index = string.find('', index)
// string operators4: int n = stoi(string)
// string operators1: string = string.substr(index1, length)

// example: 3##$%0#2#12 -> ["#$%", "", "12"]
class Codec {
public:
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string s;
        for (string str : strs)
            s += to_string(str.length()) + '$' + str;
        return s;
    }
    
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        size_t n = s.length(), p = 0 ;
        while (p < n) {
            size_t pos = s.find('$', p);
            if (pos == string::npos) break;
            size_t sz = stoi(s.substr(p, pos - p));
            strs.push_back(s.substr(pos + 1, sz));
            p = pos + sz + 1;
        }
        return strs;
    }
};

