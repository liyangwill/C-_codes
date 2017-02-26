class Solution {
public:
    bool canPermutePalindrome(string s) {
        int odd = 0, counts[256] = {0};
        for (char c : s)
            counts[c]++;
            odd += counts[c]%2 == 0 ? -1:1;
        return odd <= 1;
    }
};