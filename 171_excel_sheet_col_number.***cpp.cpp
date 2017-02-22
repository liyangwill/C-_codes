class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++)
            result = result * 26 + (s.at(i) - 'A' + 1);  //string.at(i) return index ith character;
        return result;
    }
};